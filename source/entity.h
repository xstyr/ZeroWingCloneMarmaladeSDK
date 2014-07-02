//
//  entity.h
//  Stage1
//
//  Created by Mac on 24/03/2014.
//
//

#ifndef __Stage1__entity__
#define __Stage1__entity__

#include <iostream>
#include "Iw2D.h"

class Entity
{
private:
    float angle;
    
public:
    Entity(float x, float y, float angle);
    virtual ~Entity();
    virtual void draw() = 0;
    CIwFVec2 pos;
    CIwFVec2 vec;
    CIwFVec2 size;
    void *pObjArray;
    std::string name;
    bool remove = false;
    bool damageTaken = false;
    short health = 100;
  };

class SpaceShip : public Entity {
public:
    SpaceShip (float x, float y, float angle) : Entity(x, y, angle){
        size = CIwFVec2(20,10);
    }
    virtual void    draw();
    virtual ~SpaceShip(){};
};

class Enemy : public Entity {
public:
    Enemy (float x, float y, float angle) : Entity(x, y, angle){
        size = CIwFVec2(20,10);
    }
    virtual void    draw();
    virtual ~Enemy(){};
};

class Bullet : public Entity {
public:
    Bullet (float x, float y, float angle) : Entity(x, y, angle){
        size = CIwFVec2(5,5);
    }
    virtual void    draw();
    virtual ~Bullet(){};
};

#endif /* defined(__Stage1__entity__) */

