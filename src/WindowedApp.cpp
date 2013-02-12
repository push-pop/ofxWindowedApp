#include "WindowedApp.h"

void WindowedApp::setup(){};
void WindowedApp::draw(){};

void WindowedApp::size(float height, float width){simpleWindow::setSize(height, width);}

void WindowedApp::beginDraw(){
    simpleWindow::draw();
    ofPushMatrix();
    ofTranslate(mTopLeft);
    ofRotateZ(ofRadToDeg(angle));
}
void WindowedApp::endDraw(){ofPopMatrix();}

void WindowedApp::setTuioClient (myTuioClient * _tuioClient){
	tuioClient = _tuioClient;
	//Sets client for surrounding window
	simpleWindow::setTuioClient(tuioClient);
	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&WindowedApp::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&WindowedApp::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&WindowedApp::tuioUpdated);
}


void WindowedApp::tuioAdded(ofxTuioCursor &tuioCursor){
	//TODO: Check Menu Items



}
void WindowedApp::tuioUpdated(ofxTuioCursor &tuioCursor){


}
void WindowedApp::tuioRemoved(ofxTuioCursor &tuioCursor){



}