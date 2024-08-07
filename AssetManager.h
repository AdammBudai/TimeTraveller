//
// Created by adamb on 29. 4. 2024.
//

#ifndef TIMETRAVELLER_ASSETMANAGER_H
#define TIMETRAVELLER_ASSETMANAGER_H

#include <map>
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"
#include "ECS/ECS.h"

class TextureManager;

class AssetManager {
public:
    AssetManager(Manager* man);
    ~AssetManager();
//game objects

    void CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id);



//texture managment
    void AddTexture(std::string id, const char* path);
    SDL_Texture* GetTexture(std::string id);


private:
    Manager* manager;
    std::map<std::string, SDL_Texture*> textures;

};

#endif //TIMETRAVELLER_ASSETMANAGER_H
