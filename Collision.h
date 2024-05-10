//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_COLLISION_H
#define TIMETRAVELLER_COLLISION_H
#include "SDL.h"

class ColliderComponent;

class Collision {
public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);


};

#endif //TIMETRAVELLER_COLLISION_H
