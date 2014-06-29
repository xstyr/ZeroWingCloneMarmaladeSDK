//
//  Animator.cpp
//  Stage1
//
//  Created by Mac on 07/06/2014.
//
//

#include "Animator.h"
#include "resourceManager.h"
#include <iostream>
#include "Iw2D.h"
#include "IwGx.h"

Animator::Animator(ResourceManager & _rM) : rM(_rM){}

void Animator::update(){

    CIwArray<Entity*> & entities = rM.getEntities();
    for (CIwArray<Entity*>::iterator it = entities.begin(); it != entities.end(); it++){
        (*it)->draw();
    }
}