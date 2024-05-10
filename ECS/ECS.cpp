//
// Created by adamb on 27. 4. 2024.
//
#include "ECS.h"

void Entity::addGroup(Group mGroup) {
    groupBitSet[mGroup] = true;
    manager.AddToGroup(this, mGroup);
}