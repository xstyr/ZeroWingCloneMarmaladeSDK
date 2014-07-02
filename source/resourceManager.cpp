//
//  resourceManager.cpp
//  Stage1
//
//  Created by Mac on 07/06/2014.
//
//

#include "resourceManager.h"


void ResourceManager::addEntity(SpaceShip & entity){
    entityArray.push_back(&entity);
    spaceShip = &entity;
}

void ResourceManager::addEntity(Enemy & entity){
    entityArray.push_back(&entity);
    enemyArray.push_back(&entity);
    entity.pObjArray = &enemyArray;
}

void ResourceManager::addEntity(Bullet &entity){
    entityArray.push_back(&entity);
    bulletArray.push_back(&entity);
    entity.pObjArray = &bulletArray;
}

SpaceShip & ResourceManager::getSpaceShip(){
    return * spaceShip;
}

CIwArray<Enemy*> & ResourceManager::getEnemies(){
    return enemyArray;
}

CIwArray<Bullet*> & ResourceManager::getBullets(){
    return bulletArray;
}


CIwArray<Entity*> & ResourceManager::getEntities(){
    return entityArray;
}

ResourceManager::~ResourceManager(){
    for (CIwArray<Entity*>::iterator it = entityArray.begin(); it != entityArray.end(); it++){
        delete *it;
    }
    entityArray.clear();
}

void ResourceManager::remove(Entity *e){
    int index = entityArray.find(e);
    entityArray.erase(index);
    
    //look if the object is assigned to the array
    if(e->pObjArray == &enemyArray){
        this->remove((Enemy*) e);
    }
    if(e->pObjArray == &bulletArray){
        this->remove((Bullet*) e);
    }
    
    delete e;
    
}

 void ResourceManager::remove(Bullet *e){
    int index = bulletArray.find((Bullet*)e);
    if(index != -1){
        bulletArray.erase(index);
    }
}

 void ResourceManager::remove(Enemy *e){
    int index = enemyArray.find((Enemy*)e);
    if(index != -1){
        enemyArray.erase(index);
    }
}
