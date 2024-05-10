//
// Created by adamb on 27. 4. 2024.
//

#ifndef TIMETRAVELLER_ANIMATION_H
#define TIMETRAVELLER_ANIMATION_H

struct Animation
{
        int index;
        int frames;
        int speed;

        Animation(){}

        Animation(int i, int f, int s)
        {
            index = i;
            frames = f;
            speed = s;
        }

};

#endif //TIMETRAVELLER_ANIMATION_H
