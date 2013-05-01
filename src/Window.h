#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include "ofMain.h"
#include "ofxTuio.h"

class simpleWindow
{
    public:

        simpleWindow();
        simpleWindow(ofPoint topLeft);
        virtual ~simpleWindow();

        void setPosition(float _x, float _y);
        void setPosition(ofPoint topLeft);
        void setSize(float height, float width);

            virtual void update();
            virtual void draw();
            virtual void setup(){};

        void setWindowID(int id);
        bool containsPoint(ofPoint point);
        void setBackgroundColor(ofColor mBackgroundColor);
        virtual void setTuioClient (ofxTuioClient * _tuioClient);

        ofPoint toLocalAxisSystem(ofPoint point);
        ofPoint toGlobalAxisSystem(ofPoint point);

        void	tuioAdded(ofxTuioCursor & tuioCursor);
        void	tuioRemoved(ofxTuioCursor & tuioCursor);
        void	tuioUpdated(ofxTuioCursor & tuioCursor);

        struct activeCursor{
            ofPoint cursorLoc;
            int fingerID;
        };

        ofPoint mTopLeft;


    protected:

        ofPoint lastGrabbed;
        ofPoint lastPosition;


        float windowHeight;
        float windowWidth;


        ofColor mBackgroundColor;
        float scale;
        float angle;
        float lastScale;
        float lastAngle;

        ofxTuioClient * tuioClient;

        vector <activeCursor> activeCursors;
        vector <ofxTuioCursor*> grabbingCursors;

    private:

        int windowID;
        void drawBackground();
        void drawGrabbedPoints();
        void drawAxis();

        bool isOverTopLeft(ofPoint point);
        bool isOverBottomRight(ofPoint point);

        void setGrabbed(bool grabbed, ofxTuioCursor &cursor);
};

#endif // WINDOW_H
