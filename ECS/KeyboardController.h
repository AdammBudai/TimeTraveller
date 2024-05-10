//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_KEYBOARDCONTROLLER_H
#define TIMETRAVELLER_KEYBOARDCONTROLLER_H

#include "../Game.h"
#include "ECS.h"
#include "Components.h"



class KeyboardController : public Component {

private:

    bool shootLeft;
    bool shootRight;


public:

    TransformComponent *transform;
    SpriteComponent *sprite;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        sprite =&entity->getComponent<SpriteComponent>();
    }

    void update() override {
        if (Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = -1;
                    sprite->Play("Up");
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    sprite->Play("Walk");
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    sprite->Play("Down");
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    sprite->Play("Walk");
                    break;
                case SDLK_SPACE:
                    if (transform->velocity.x < 0) {
                        // Facing left
                        Game::assets->CreateProjectile(Vector2D(transform->position.x - 10, transform->position.y), Vector2D(-2, 0), 200, 1, "projectile_side");
                    } else if (transform->velocity.x > 0) {
                        // Facing right
                        Game::assets->CreateProjectile(Vector2D(transform->position.x + 10, transform->position.y), Vector2D(2, 0), 200, 1, "projectile_side");
                    } else if (transform->velocity.y < 0) {
                        // Facing up
                        if (shootLeft) {
                            Game::assets->CreateProjectile(Vector2D(transform->position.x - 7, transform->position.y - 10), Vector2D(0, -2), 200, 1, "projectile");
                            shootLeft = false;
                            shootRight = true;
                        } else {
                            Game::assets->CreateProjectile(Vector2D(transform->position.x + 7, transform->position.y - 10), Vector2D(0, -2), 200, 1, "projectile");
                            shootRight = false;
                            shootLeft = true;
                        }
                    } else if (transform->velocity.y > 0) {
                        // Facing down
                        if (shootLeft) {
                            Game::assets->CreateProjectile(Vector2D(transform->position.x - 7, transform->position.y + 10), Vector2D(0, 2), 200, 1, "projectile");
                            shootLeft = false;
                            shootRight = true;
                        } else {
                            Game::assets->CreateProjectile(Vector2D(transform->position.x + 7, transform->position.y + 10), Vector2D(0, 2), 200, 1, "projectile");
                            shootRight = false;
                            shootLeft = true;
                        }
                    }
                        // Idle
                    else{
                        Game::assets->CreateProjectile(Vector2D(transform->position.x + 10, transform->position.y), Vector2D(2, 0), 200, 1, "projectile_side");
                    }
                    break;
                default:
                    break;
            }
        }

        if(Game::event.type == SDL_KEYUP) {
            switch(Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_SPACE:
                    break;
                case SDLK_ESCAPE:
                    Game::isRunning = false;
                default:
                    break;
            }
        }
    }
};
#endif //TIMETRAVELLER_KEYBOARDCONTROLLER_H
