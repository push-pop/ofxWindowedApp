#ifndef MENUITEM_H
#define MENUITEM_H

#pragma once

#include "ofMain.h"
#include "Window.h"
#include "ofxTuio.h"


class MenuItem : public simpleWindow
{
    public:
        MenuItem();
        MenuItem(ofPoint topLeft);
        MenuItem(string _label, ofPoint topLeft);
        virtual ~MenuItem();

        ofColor mBackgroundColor;
        string getLabel();

        void draw();

        string mLabel;
    ofxTuioClient *mTuioClient;


    protected:
        ofPoint menuPosition;

    private:

        string action;
        static const int ITEM_MARGIN = 10;
        static const int ITEM_HEIGHT = 50;
        static const int ITEM_WIDTH = 600;



};

#endif // MENUITEM_H
