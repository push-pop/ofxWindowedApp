#include "fractalTree.h"

void FractalTreeApp::setup() {


    size(600, 600);

    n = 0;
    setPosition(100, 100);

}

void FractalTreeApp::update() {
    theta = 90;
    if(activeCursors.size() == 0){
        running = false;
        n=0;
    }
    if(activeCursors.size() >= 1){

        if(!running)
            running = true;

        IC = ofPoint(activeCursors[0].cursorLoc);

        if(activeCursors.size() >= 2)
        {
            rotVec = activeCursors[1].cursorLoc - activeCursors[0].cursorLoc;
            theta = rotVec.angle(ofVec2f(1,0));
            ratio = abs(rotVec.length()/1000);
        }

    }



    startLength = ratio*(IC.y-cos(-theta));
    simpleWindow::update();
    WindowedApp::beginDraw();
  if(running)
    if (n<10)
        n+=1;


    WindowedApp::endDraw();

}
void FractalTreeApp::branch(float h, int n)
{
    if (n < 1)
        return;

        h = h*ratio;

        n-=1;
        ofPushMatrix();
        ofRotate(theta);
        ofLine(0,0,0,-h);
        ofTranslate(0,-h);
        branch(h, n);
        ofPopMatrix();

        ofPushMatrix();
        ofRotate(-theta);
        ofLine(0,0,0,-h);
        ofTranslate(0,-h);
        branch(h, n);
        ofPopMatrix();

}

void FractalTreeApp::draw() {
    WindowedApp::beginDraw();
if(running){
    float degs = 90;
    //theta = ofDegToRad(degs);
    ofTranslate(IC);
    ofLine(0,0,0,-startLength);
    ofTranslate(0,-startLength);
    branch(startLength, n);
    }
    WindowedApp::endDraw();
}







void FractalTreeApp::setTuioClient (ofxTuioClient * _tuioClient){

    	tuioClient = _tuioClient;

    //cout << "Hello" << endl;

	//Sets client for surrounding window
	WindowedApp::setTuioClient(tuioClient); // Allows the inheritance class functions to be called as well

	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&FractalTreeApp::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&FractalTreeApp::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&FractalTreeApp::tuioUpdated);


}


void FractalTreeApp::tuioAdded(ofxTuioCursor &tuioCursor){
	//TODO: Check Menu Items
            ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
            addedCursor = toLocalAxisSystem(addedCursor);




}
void FractalTreeApp::tuioUpdated(ofxTuioCursor &tuioCursor){
                ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
            addedCursor = toLocalAxisSystem(addedCursor);
            IC = addedCursor;


}
void FractalTreeApp::tuioRemoved(ofxTuioCursor &tuioCursor){
    n=0;
    running=false;



}
