//
// Created by adamb on 27. 4. 2024.
//

#include "Map.h"
#include "Game.h"
#include <fstream>
#include "ECS\ECS.h"
#include "ECS\Components.h"


extern Manager manager;


Map::Map(std::string tID, int ms, int ts) : texID(tID), mapscale(ms), tilesize(ts){
    scaledSize = ms * ts;

}

Map::~Map() {
}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
    char  c;
    std::fstream mapFile;
    mapFile.open(path);

    int srcX, srcY;
    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {

            mapFile.get( c);
            srcY = atoi(& c) * tilesize;
            mapFile.get( c);
            srcX = atoi(& c) * tilesize;
            AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
            mapFile.ignore();
        }
    }
    mapFile.ignore();

    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {
            mapFile.get( c);
            if(c == '1') {
                auto& tcol(manager.addEntity());
                tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
                tcol.addGroup(Game::groupColliders);
            }
            mapFile.ignore();

        }
    }

    mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos) {

    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tilesize, mapscale,  texID);
    tile.addGroup(Game::groupMap);
}



