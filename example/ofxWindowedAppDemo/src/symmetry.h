#ifndef SYMMETRY_H
#define SYMMETRY_H

#include "WindowedApp.h"


class SymmetryApp : public WindowedApp
{

    public:
        bool running = false;
        void setup();
        void update();
        void draw();

        ofVec2f rotVec;

        ofPoint activePt;
        float rad = 200;
        float newTheta;
        float radVel;
        float xLen;
        float xVel;
        int divs;
        float thetaVel = 0;



    ofxTuioClient *tuioClient;
	void	setTuioClient (ofxTuioClient * _tuioClient);

	void	tuioAdded(ofxTuioCursor & tuioCursor);
	void	tuioRemoved(ofxTuioCursor & tuioCursor);
	void	tuioUpdated(ofxTuioCursor & tuioCursor);

    protected:
    private:
};

#endif // SYMMETRY_H

