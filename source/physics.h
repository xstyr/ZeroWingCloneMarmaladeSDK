//
//  physics.h
//  Stage1
//
//  Created by Mac on 03/06/2014.
//
//

#ifndef Stage1_physics_h
#define Stage1_physics_h
#include "entity.h"
#include "resourceManager.h"

class Physics{
public:
    void update();
    Physics(ResourceManager &rM);
private:
    ResourceManager & rM;
    bool inbounds(Entity & e);
    void translate(Entity & e, CIwFVec2 & v);
    bool hitTest(Entity & a, Entity & b);
};


#endif
