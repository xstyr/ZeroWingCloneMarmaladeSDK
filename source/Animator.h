//
//  Animator.h
//  Stage1
//
//  Created by Mac on 07/06/2014.
//
//

#ifndef __Stage1__Animator__
#define __Stage1__Animator__

#include <iostream>
#include "resourceManager.h"

class Animator{
private:
    ResourceManager & rM;
public:
    Animator(ResourceManager & _rM);
    void update();
};

#endif /* defined(__Stage1__Animator__) */
