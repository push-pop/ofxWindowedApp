#ifndef FRACTALTREE_H
#define FRACTALTREE_H

#include "WindowedApp.h"


class FractalTreeApp : public WindowedApp
{

    public:
        bool running = false;
        void setup();
        void update();
        void draw();
        const int MAX_ITERS = 200;
        ofPoint IC;
        float theta;
        int startLength = 300;
        float ratio = 0.6;
        void branch(float h, int n);
        ofVec2f rotVec;
        int n;
    ofxTuioClient *tuioClient;
	void	setTuioClient (ofxTuioClient * _tuioClient);

	void	tuioAdded(ofxTuioCursor & tuioCursor);
	void	tuioRemoved(ofxTuioCursor & tuioCursor);
	void	tuioUpdated(ofxTuioCursor & tuioCursor);

    protected:
    private:
};

#endif // FRACTAL_TREE
