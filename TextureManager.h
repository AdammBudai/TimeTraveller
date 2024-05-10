//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_TEXTUREMANAGER_H
#define TIMETRAVELLER_TEXTUREMANAGER_H

class AssetManager;
#include "Game.h"


class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);

};

#endif //TIMETRAVELLER_TEXTUREMANAGER_H
