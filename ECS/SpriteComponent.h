//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_SPRITECOMPONENT_H
#define TIMETRAVELLER_SPRITECOMPONENT_H

#include "SDL.h"
#include "../TextureManager.h"
#include "Components.h"
#include "Animation.h"
#include <map>
#include "../AssetManager.h"



class SpriteComponent : public Component {
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    const char* path;

    bool animated = false;
    int frames = 0;
    int speed = 100;


public:

    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent() = default;

    SpriteComponent(std::string id)  {
        setTex(id);
    }

    SpriteComponent(std::string id, bool isAnimated)
    {
        animated = isAnimated;

        Animation idle = Animation(0,2,200);
        Animation walk = Animation(1,3,200);
        Animation down= Animation(2,3,200);
        Animation up= Animation(3,3,200);

        animations.emplace("Idle", idle);
        animations.emplace("Walk", walk);
        animations.emplace("Down", down);
        animations.emplace("Up", up);

        Play("Idle");

        setTex(id);
    }
    ~SpriteComponent()
    {
        //SDL_DestroyTexture(texture);
    }

    void setTex(std::string id) {
        texture = Game::assets->GetTexture(id);
    }


    void init() override {
        transform = &entity->getComponent<TransformComponent>();


        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;

    }

    void update() override
    {
        if(animated)
        {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }

        srcRect.y = animIndex * transform ->height;

        destRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
        destRect.y = static_cast<int>(transform->position.y) - Game::camera.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;

    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
    }

    void Play(const char* animName)
    {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;

    }
};

#endif //TIMETRAVELLER_SPRITECOMPONENT_H
