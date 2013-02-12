#ifndef WINAPP_H
#define WINAPP_H

#include "WindowedApp.h"
class winApp : public WindowedApp
{
    public:

    ofPoint cirPos;
    float xVel;
    float yVel;
    float radius;
    ofColor color;


        void setup();
        void update();
        void draw();

                    myTuioClient * tuioClient;
	void	setTuioClient (myTuioClient * _tuioClient);

	void	tuioAdded(ofxTuioCursor & tuioCursor);
	void	tuioRemoved(ofxTuioCursor & tuioCursor);
	void	tuioUpdated(ofxTuioCursor & tuioCursor);


    protected:
    private:
};

#endif // WINAPP_H
