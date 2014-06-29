//
//  physics.cpp
//  Stage1
//
//  Created by Mac on 03/06/2014.
//
//

#include "physics.h"
#include "IwGx.h"

Physics::Physics(ResourceManager & _rM) : rM(_rM){}

void Physics::update(){
    
    /****
     UPDATE POSITIONS
     ****/
    CIwArray<Entity*> & entities = rM.getEntities(); //move all entities
    for (CIwArray<Entity*>::iterator it = entities.begin(); it != entities.end(); it++){
        Entity * e = *it;
        //maybe move by angle + force?
        this->translate(* e, e->vec);
    }
    SpaceShip * e = &rM.getSpaceShip();
    if(not inbounds(* e)){
        //move the ship back
        CIwFVec2 revVec = CIwFVec2( - e->vec.x, - e->vec.y);
        this->translate(* e, revVec);
    }    
    
    /****
     HITTEST BULLET TO ENEMY
     ****/
    CIwArray<Bullet*> & bulletArray = rM.getBullets();
    for (CIwArray<Bullet*>::iterator b = bulletArray.begin(); b != bulletArray.end(); b++){
        Bullet * bullet = *b;
        CIwArray<Enemy*> & enemyArray = rM.getEnemies();
        for (CIwArray<Enemy*>::iterator en = enemyArray.begin(); en != enemyArray.end(); en++){
            Enemy * enemy = *en;
            if(hitTest(* bullet, * enemy)){
                bullet->remove = true;
                enemy->damageTaken = true;
                if(enemy->health <= 0){
                    enemy->remove = true;
                }
            }
        }
    }
    
    
    /****
     DELETE ENTITIES SET TO REMOVE
     ****/
    CIwArray<Entity*> & entites = rM.getEntities();
    CIwArray<Entity*>::iterator it = entites.begin();
    //if we are removing elements, we need to be careful with the iterator!
    while(it != entites.end()){
        Entity * e = *it;
        if( e->remove || (not inbounds(* e))){
            rM.remove(e);
        } else {
            ++it;
        }
    }
}

void Physics::translate(Entity & e, CIwFVec2 & v)
{
    e.pos += v;
}

bool Physics::hitTest(Entity & a, Entity & b){
    
    return not (
                (a.pos.y + a.size.y < b.pos.y) ||
                (a.pos.y > b.pos.y + b.size.y) ||
                (a.pos.x > b.pos.x + b.size.x) ||
                (a.pos.x + a.size.x < b.pos.x) );

}

bool Physics::inbounds(Entity & e)
{
    if((e.pos.x < 0) || (e.pos.x + e.size.x > IwGxGetScreenWidth())){
        return false;
    }
    
    if((e.pos.y < 0) || (e.pos.y + e.size.y  > IwGxGetScreenHeight())){
        return false;
    }
    
    return true;
}
