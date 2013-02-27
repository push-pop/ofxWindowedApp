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
        ~simpleWindow();

        void setPosition(int _x, int _y);
        void setPosition(ofPoint topLeft);
        void setSize(float height, float width);
        void update();
        void draw();

        void setBackgroundColor(ofColor mBackgroundColor);

        ofPoint toLocalAxisSystem(ofPoint point);





        ofPoint toGlobalAxisSystem(ofPoint point);





    protected:
        ofPoint lastGrabbed;
        ofPoint lastPosition;
        ofPoint mTopLeft;

        float windowHeight;
        float windowWidth;


        ofColor mBackgroundColor;
        float scale;
        float angle;
        float lastScale;
        float lastAngle;

        ofxTuioClient * tuioClient;
        void	setTuioClient (ofxTuioClient * _tuioClient);

        void	tuioAdded(ofxTuioCursor & tuioCursor);
        void	tuioRemoved(ofxTuioCursor & tuioCursor);
        void	tuioUpdated(ofxTuioCursor & tuioCursor);

        vector <ofxTuioCursor*> grabbingCursors;
    private:


        void drawBackground();
        void drawGrabbedPoints();
        void drawAxis();

        bool isOverTopLeft(ofPoint point);
        bool isOverBottomRight(ofPoint point);



        void setGrabbed(bool grabbed, ofxTuioCursor &cursor);
};

#endif // WINDOW_H
