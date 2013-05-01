#include "symmetry.h"

void SymmetryApp::setup() {


    size(600, 600);
    setPosition(100, 100);
    radVel=.5;
    xLen = 0;
    xVel = .1;
    rad = 0;
    divs = 1;
    activePt = ofPoint(10, 10, 0);

}

void SymmetryApp::update() {


    if(activeCursors.size() >= 1){
        activePt = activeCursors[0].cursorLoc;
        if(activeCursors.size() >= 2)
        {
            rotVec = activeCursors[1].cursorLoc - activeCursors[0].cursorLoc;
            thetaVel = (rotVec.angle(ofVec2f(1,0)))/2*PI;

            divs = abs(rotVec.length()/100);
        }

    }



//    startLength = ratio*(IC.y-cos(-theta));
    simpleWindow::update();
    WindowedApp::beginDraw();



    WindowedApp::endDraw();

}

void SymmetryApp::draw() {
    WindowedApp::beginDraw();
  for(float theta = newTheta; theta < 2*PI+newTheta; theta += PI/divs)
  {
    ofSetColor(ofColor(rad*theta/PI,200*theta/(2*PI),0, 127));
    ofPushMatrix();
    ofTranslate(windowWidth/2+rad*cos(theta), windowHeight/2+rad*sin(theta));
    ofRotate(-theta);
    ofEllipse(0,0,activePt.x,activePt.y);
    ofPopMatrix();
  }

    newTheta+=thetaVel;
    if(rad > windowWidth/2 || rad < -windowWidth/2){
      xVel *=-1;
      radVel*=-1;
    }
    rad+=radVel;
    xLen+=xVel;

    WindowedApp::endDraw();
}







void SymmetryApp::setTuioClient (ofxTuioClient * _tuioClient){

    	tuioClient = _tuioClient;

    //cout << "Hello" << endl;

	//Sets client for surrounding window
	WindowedApp::setTuioClient(tuioClient); // Allows the inheritance class functions to be called as well

	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&SymmetryApp::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&SymmetryApp::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&SymmetryApp::tuioUpdated);


}


void SymmetryApp::tuioAdded(ofxTuioCursor &tuioCursor){
	//TODO: Check Menu Items
            ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
            addedCursor = toLocalAxisSystem(addedCursor);




}
void SymmetryApp::tuioUpdated(ofxTuioCursor &tuioCursor){



}
void SymmetryApp::tuioRemoved(ofxTuioCursor &tuioCursor){




}

