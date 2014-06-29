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

#include "Input.h"


/*int32 Input::KeyboardEventCB(s3eKeyboardEvent* event, void* userData)
{
    s3eKey key = event->m_Key;
    Input * self = (Input *) userData;
    
    if(key == s3eKeyUp){
        self->kIsDown_Up = self->isKeyDown(key);
    }
    ...
    return 0;
}*/

bool Input::isKeyDown(s3eKey key) const
{
    return (s3eKeyboardGetState(key) & S3E_KEY_STATE_DOWN) == S3E_KEY_STATE_DOWN;
}

bool Input::isKeyUp(s3eKey key) const
{
    return (s3eKeyboardGetState(key) & S3E_KEY_STATE_UP) == S3E_KEY_STATE_UP;
}

bool Input::wasKeyPressed(s3eKey key) const
{
    return (s3eKeyboardGetState(key) & S3E_KEY_STATE_PRESSED) == S3E_KEY_STATE_PRESSED;
}

bool Input::wasKeyReleased(s3eKey key) const
{
    return (s3eKeyboardGetState(key) & S3E_KEY_STATE_RELEASED) == S3E_KEY_STATE_RELEASED;
}





Input::Input()
{
//    s3eKeyboardRegister(S3E_KEYBOARD_KEY_EVENT, (s3eCallback) *KeyboardEventCB, this);
}

void Input::update()
{
    s3eKeyboardUpdate();
}