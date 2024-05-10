#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "AssetManager.h"
#include "logger.h"



Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = {0,0,1024,1024};

AssetManager* Game::assets = new AssetManager(&manager);


bool Game::isRunning = false;


auto& player(manager.addEntity());


Game::Game(){}
Game::~Game(){}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        }
        isRunning = true;
    }

    assets->AddTexture("terrain", "assets/tileset.png");
    assets->AddTexture("player", "assets/player_anims.png");
    assets->AddTexture("projectile", "assets/strela.png");
    assets->AddTexture("projectile_side", "assets/projectile_side.png");
    Logger::getLogger()->info("Game initialized. For other map change assets");

    map = new Map("terrain", 2, 32);

    map->LoadMap("assets/map1.map", 32, 32);

    player.addComponent<TransformComponent>(1.5);
    player.addComponent<SpriteComponent>("player",true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& enemies(manager.getGroup(Game::groupEnemies));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));

void Game::handleEvents() {

    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPos = player.getComponent<TransformComponent>().position;

    manager.refresh();
    manager.update();

    for(auto& c : colliders)
    {
        SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
        if(Collision::AABB(playerCol, cCol))
        {
            player.getComponent<TransformComponent>().position = playerPos;
            Logger::getLogger()->info("Collision detected (Player hits the wall).");
        }
    }
    for (auto& p : projectiles)
    {
        SDL_Rect pCol = p->getComponent<ColliderComponent>().collider;
        for (auto& c : colliders)
        {
            SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
            if (Collision::AABB(pCol, cCol))
            {
                p->destroy();
                Logger::getLogger()->info("Projectile destroyed");
                break;
            }
        }
    }

    camera.x = player.getComponent<TransformComponent>().position.x - 400;
    camera.y = player.getComponent<TransformComponent>().position.y - 220;

    if(camera.x < 0)
    {
        camera.x = 0;
    }

    if(camera.y < 0)
    {
        camera.y = 0;
    }

    if(camera.x > camera.w)
    {
        camera.x = camera.w;
    }
    if(camera.y > camera.h)
    {
        camera.y = camera.h;
    }

}



void Game::render() {

    SDL_RenderClear(renderer);
    for(auto& t : tiles)
    {
        t->draw();
    }

//    for(auto& c : colliders)
//    {
//        c->draw();
//    }
    for(auto& p : players)
    {
        p->draw();
    }
    for(auto& e : enemies)
    {
        e->draw();
    }

    for(auto& pr : projectiles)
    {
        pr->draw();
    }
    SDL_RenderPresent(renderer);
}


void Game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

