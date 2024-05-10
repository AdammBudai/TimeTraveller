//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_MAP_H
#define TIMETRAVELLER_MAP_H

#include <string>
class Map {
public:
    Map(std::string tID, int ms, int ts);
    ~Map();

    void LoadMap(std::string path, int sizeX, int sizeY);
    void AddTile(int srcX, int srcY, int xpos, int ypos);

private:
    std::string texID;
    int mapscale;
    int tilesize;
    int scaledSize;



};

#endif //TIMETRAVELLER_MAP_H
