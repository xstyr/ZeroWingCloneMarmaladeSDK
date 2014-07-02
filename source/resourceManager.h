//
//  resourceManager.h
//  Stage1
//
//  Created by Mac on 07/06/2014.
//
//

#ifndef __Stage1__resourceManager__
#define __Stage1__resourceManager__

#include <iostream>
#include "entity.h"

class ResourceManager{
    
private:
        CIwArray<Entity*> entityArray;
        CIwArray<Enemy*> enemyArray;
        CIwArray<Bullet*> bulletArray;
        SpaceShip * spaceShip;
        void remove(Bullet * e);
        void remove(Enemy * e);
        
public:
    void addEntity(SpaceShip & e);
    void addEntity(Enemy & e);
    void addEntity(Bullet & e);
    
    CIwArray<Entity*> & getEntities();
    CIwArray<Enemy*> & getEnemies();
    CIwArray<Bullet*> & getBullets();
    SpaceShip & getSpaceShip();
    ~ResourceManager();
    void remove(Entity * e);
};



#endif /* defined(__Stage1__resourceManager__) */
