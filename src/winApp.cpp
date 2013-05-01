#include "winApp.h"

void winApp::setup(){

}

// Update parameters
void winApp::update() {

    simpleWindow::update();
    WindowedApp::beginDraw();

    WindowedApp::endDraw();
}

// Update graphic using new values
void winApp::draw() {
    WindowedApp::beginDraw();

    WindowedApp::endDraw();
}


void winApp::setTuioClient (ofxTuioClient * _tuioClient){
	tuioClient = _tuioClient;

	//Sets client for surrounding window
	WindowedApp::setTuioClient(tuioClient); // Allows the inheritance class functions to be called as well

	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&winApp::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&winApp::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&winApp::tuioUpdated);
}

void winApp::tuioAdded(ofxTuioCursor &tuioCursor){

}

void winApp::tuioUpdated(ofxTuioCursor &tuioCursor){

}

void winApp::tuioRemoved(ofxTuioCursor &tuioCursor){

}
