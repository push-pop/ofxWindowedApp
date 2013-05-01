#pragma once

#include "ofMain.h"
#include "WindowedApp.h"
#include "WindowManager.h"
#include "ofxTuio.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

            ofxTuioClient  mTuioClient;
            WindowManager mWindowManager;

        void tuioAdded(ofxTuioCursor & tuioCursor);
        void tuioRemoved(ofxTuioCursor & tuioCursor);
        void tuioUpdated(ofxTuioCursor & tuioCursor);

};
