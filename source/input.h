/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */

#if !defined(_INPUT_H)
#define _INPUT_H

#include "s3ePointer.h"
#include "s3eKeyboard.h"
#include "s3eOSReadString.h"

#define MAX_TOUCHES     10

/*
 @class Input
 
 @brief Input - The Input class is responsible for handling all pointer input.
 
 Example usage:
 @code
 // Set up input systems
 g_pInput = new Input();
 
 // Update
 while (!s3eDeviceCheckQuitRequest())
 {
 // Update input system
 g_pInput->Update();
 }
 
 // Cleanup
 delete g_pInput;
 @endcode
 
 */
class Input
{
public:    
    Input();
    
    bool isKeyDown(s3eKey key) const;
    bool isKeyUp(s3eKey key) const;
    bool wasKeyPressed(s3eKey key) const;
    bool wasKeyReleased(s3eKey key) const;
    
    void            update();

    
    // Callbacks
    //int32     static KeyboardEventCB(s3eKeyboardEvent* event, void* userData);
};

#endif  // _INPUT_H