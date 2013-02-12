#include "winApp.h"



void winApp::setup(){
    size(600, 600);
    xVel = ofRandom(1,4);
    yVel = ofRandom(1,4);
    radius = 20;
    cirPos = ofPoint(radius, radius);
    color = ofColor(255, 0, 0, 127);
    setPosition(100, 100);
}

void winApp::update(){
    simpleWindow::update();
    WindowedApp::beginDraw();
    cirPos.x += xVel;
    cirPos.y += yVel;

    if(cirPos.x + radius > windowWidth || cirPos.x - radius < 0){
        xVel*=-1;
        color = ofColor(0,255,0,127);
        }
    if(cirPos.y + radius > windowHeight || cirPos.y - radius < 0){
        color = ofColor(0,0,255,127);
        yVel*=-1;}
    WindowedApp::endDraw();
}

void winApp::draw() {
    WindowedApp::beginDraw();
   // ofEnableAlphaBlending();
    ofFill();
    ofSetColor(color);
    ofCircle(cirPos, radius);
    //ofCircle(300, 100, radius);
    ofDisableAlphaBlending();
    //ofPopMatrix();
    WindowedApp::endDraw();


}


void winApp::setTuioClient (myTuioClient * _tuioClient){
	tuioClient = _tuioClient;
	//Sets client for surrounding window
	WindowedApp::setTuioClient(tuioClient);
	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&winApp::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&winApp::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&winApp::tuioUpdated);
}


void winApp::tuioAdded(ofxTuioCursor &tuioCursor){
	//TODO: Check Menu Items


}
void winApp::tuioUpdated(ofxTuioCursor &tuioCursor){


}
void winApp::tuioRemoved(ofxTuioCursor &tuioCursor){



}
