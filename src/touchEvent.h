#pragma once
#include "ofMain.h"
#include "Menu.h"
#include "ofxTuio.h"
#ifndef TOUCHEVENT_H
#define TOUCHEVENT_H


class touchEvent : ofEventArgs
{
    public:

        ofxTuioCursor* cursor;
        //Menu* menu;
        string action;

        touchEvent(){
            cursor = NULL;

        }

        static ofEvent <touchEvent> events;


};

#endif // TOUCHEVENT_H
