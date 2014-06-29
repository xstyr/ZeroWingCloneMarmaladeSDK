//
//  entity.cpp
//  Stage1
//
//  Created by Mac on 24/03/2014.
//
//

#include "entity.h"
#include "Iw2D.h"
#include "IwGx.h"
#include "resourceManager.h"
#include <iostream>

Entity::Entity(float x, float y, float incAngle)
{
    angle = incAngle;
    vec = CIwFVec2(0,0);
    size = CIwFVec2(100,100);
    pos = CIwFVec2(x,y);
    
    
    std::cout << "INIT";
}

Entity::~Entity(){
}

void Bullet::draw(){
    
    CIwMaterial* pMat = IW_GX_ALLOC_MATERIAL();
    // Set this as the active material
    IwGxSetMaterial(pMat);
    
    static CIwSVec2 xy3[3];
    xy3[0].x = pos.x, xy3[0].y = pos.y;
    xy3[1].x = pos.x, xy3[1].y = pos.y + size.y;
    xy3[2].x = pos.x + size.x, xy3[2].y = pos.y + size.y/2;
    IwGxSetVertStreamScreenSpace(xy3, 3);
    // Set up vertex colours
    static CIwColour cols[4] =
    {
        {0xff, 0xff, 0xff},
        {0xff, 0xff, 0xff},
        {0xff, 0xff, 0xff},
    };
    IwGxSetColStream(cols, 3);
    // Draw single triangle
    IwGxDrawPrims(IW_GX_TRI_LIST, NULL, 3);
    // End drawing
    IwGxFlush();
}


void SpaceShip::draw(){
    CIwMaterial* pMat = IW_GX_ALLOC_MATERIAL();
    // Set this as the active material
    IwGxSetMaterial(pMat);
    
    static CIwSVec2 xy3[3];
    xy3[0].x = pos.x, xy3[0].y = pos.y;
    xy3[1].x = pos.x, xy3[1].y = pos.y + size.y;
    xy3[2].x = pos.x + size.x, xy3[2].y = pos.y + size.y/2;
    IwGxSetVertStreamScreenSpace(xy3, 3);
    // Set up vertex colours
    static CIwColour cols[4] =
    {
        {0xff, 0xff, 0xff},
        {0xff, 0xff, 0xff},
        {0xff, 0xff, 0xff},
    };
    IwGxSetColStream(cols, 3);
    // Draw single triangle
    IwGxDrawPrims(IW_GX_TRI_LIST, NULL, 3);
    // End drawing
    IwGxFlush();
}
void Enemy::draw(){
    CIwMaterial* pMat = IW_GX_ALLOC_MATERIAL();
    // Set this as the active material
    IwGxSetMaterial(pMat);
    
    static CIwSVec2 xy3[3];
    xy3[0].x = pos.x + size.x, xy3[0].y = pos.y;
    xy3[1].x = pos.x, xy3[1].y = pos.y + size.y/2;
    xy3[2].x = pos.x+ size.x, xy3[2].y = pos.y + size.y;
    IwGxSetVertStreamScreenSpace(xy3, 3);
    // Set up vertex colours
    CIwColour *colour = IW_GX_ALLOC(CIwColour, 4);
    
    if(damageTaken){
        colour->Set(0xff, 0x00, 0x00);
        damageTaken = false;
        health -= 5;
    } else {
        colour->Set(0xff, 0xff, 0xff);
    }
    CIwColour* cols = new CIwColour[3];
    cols[0] = *colour;
    cols[1] = *colour;
    cols[2] = *colour;

    IwGxSetColStream(cols);
    // Draw single triangle
    IwGxDrawPrims(IW_GX_TRI_LIST, NULL, 3);
    // End drawing
    IwGxFlush();
    
    delete cols;
}
