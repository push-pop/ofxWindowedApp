
#ifndef TUIOPONG_H
#define TUIOPONG_H

#include "WindowedApp.h"
class tuioPong : public WindowedApp
{
    public:



        void setup();
        void update();
        void draw();

                    ofxTuioClient * tuioClient;
	void	setTuioClient (ofxTuioClient * _tuioClient);

	void	tuioAdded(ofxTuioCursor & tuioCursor);
	void	tuioRemoved(ofxTuioCursor & tuioCursor);
	void	tuioUpdated(ofxTuioCursor & tuioCursor);


    protected:
    private:
    bool puckHitHorizWall();
    int puckHitVertWall();
    bool puckHitPaddle();
    void resetPuck();
};

#endif // TUIOPONG_H
