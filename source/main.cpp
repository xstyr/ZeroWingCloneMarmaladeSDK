#include "s3e.h"
#include "Iw2D.h"
#include "IwGx.h"
#include "input.h"
#include "entity.h"
#include "physics.h"
#include "Animator.h"
#include "resourceManager.h"
#include <iostream>


int main(){
    
    //Init the 2D gfx system
    Iw2DInit();
    

    Input * g_pInput = new Input();

    
    ResourceManager * g_ResManager = new ResourceManager();
    Physics * g_Physics = new Physics(*g_ResManager);
    Animator * g_Animator = new Animator(*g_ResManager);
    SpaceShip * spaceship = new SpaceShip(100, 100, -PI/2);
    
    Enemy * enemy = new Enemy(400, 100, 0);
    
    
    spaceship->name = "spaceship";
    g_ResManager->addEntity(*spaceship);
    g_ResManager->addEntity(*enemy);
    
    int16 counter = 0;
    int16 speed = 5;

    //Loop forever, until OS interupt
    while(!s3eDeviceCheckQuitRequest()){
        
        //Clear the drawing surface
        Iw2DSurfaceClear(0xff222222);
        
        g_pInput->update();
        
        spaceship->vec.x = 0;
        spaceship->vec.y = 0;
        if(g_pInput->isKeyDown(s3eKeyRight)){
            spaceship->vec.x += speed;
        }
        if(g_pInput->isKeyDown(s3eKeyLeft)){
            spaceship->vec.x -= speed;
        }
        if(g_pInput->isKeyDown(s3eKeyUp)){
            spaceship->vec.y -= speed;
        }
        if(g_pInput->isKeyDown(s3eKeyDown)){
            spaceship->vec.y += speed;
        }

        
        if(g_pInput->isKeyDown(s3eKeySpace)){
            if(++counter % 2 == 0){
                Bullet * bullet = new Bullet(spaceship->pos.x +spaceship->size.x  + 15,
                                             spaceship->pos.y + 0.5*spaceship->size.y - 2, -PI/2);
                bullet->vec.x = 8;
                bullet->name = "bullet";
                g_ResManager->addEntity(*bullet);
            }
        }
        
        
        g_Physics->update();
        g_Animator->update();
               //Show drawing surface
        Iw2DSurfaceShow();
        
        //Yield to the OS
        s3eDeviceYield(0);
        
    }
    
    
    delete g_ResManager;
    delete g_pInput;
    delete g_Physics;
    delete g_Animator;
    
    Iw2DTerminate();
    
    return 0;
    
    
}