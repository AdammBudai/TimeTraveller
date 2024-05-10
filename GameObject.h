//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_GAMEOBJECT_H
#define TIMETRAVELLER_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();
    void Update();
    void Render();


private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

};
#endif //TIMETRAVELLER_GAMEOBJECT_H
