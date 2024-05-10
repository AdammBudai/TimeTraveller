//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_TRANSFORMCOMPONENT_H
#define TIMETRAVELLER_TRANSFORMCOMPONENT_H
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component {


public:

    Vector2D position;
    Vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;


    int speed = 3;


    TransformComponent() {
       position.zero();
    }

    TransformComponent(int sc) {
        position.x = 500;
        position.y = 320;
        scale = sc;
    }


    TransformComponent(float x, float y) {
        position.zero();
    }

    TransformComponent(float x, float y, int w, int h, int s) {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = s;
    }

    void init() override {
      velocity.zero();
    }

    void update() override {

        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

    }

};

#endif //TIMETRAVELLER_TRANSFORMCOMPONENT_H
