#include "Window.h"

simpleWindow::simpleWindow(){

    mBackgroundColor = ofColor(255, 0, 0, 127);
    mTopLeft = ofPoint(200,200);
    scale=1;
    angle=0;

}

simpleWindow::simpleWindow(ofPoint _topLeft){
    scale = 1;
    angle = 0;

    lastAngle = 0.0;
    mBackgroundColor = ofColor(255, 255, 255, 127);
    mTopLeft = _topLeft;

}

simpleWindow::~simpleWindow(){
    //dtor
}

void simpleWindow::setPosition(float _x, float _y){

    mTopLeft = ofPoint(_x, _y);

}

void simpleWindow::setPosition(ofPoint topLeft){
    mTopLeft = topLeft;
}

void simpleWindow::setSize(float width, float height){
    windowHeight = height;
    windowWidth = width;
}
void simpleWindow::setBackgroundColor(ofColor newColor){
    mBackgroundColor = newColor;
}


bool simpleWindow::isOverTopLeft(ofPoint point){
    return (ofDist(point.x, point.y, mTopLeft.x, mTopLeft.y) < 20);
}
bool simpleWindow::isOverBottomRight(ofPoint point){
    ofPoint temp = toLocalAxisSystem(point);
    float d = ofDist(temp.x, temp.y,
                      windowWidth, windowHeight);
    return (d < 50);
}

ofPoint simpleWindow::toGlobalAxisSystem(ofPoint point){
    ofPushMatrix();
    ofTranslate(mTopLeft);
    ofVec3f origin(0,0,1);
    ofPoint shiftedPoint = point.getRotatedRad(angle, origin);
    ofPopMatrix();
    return shiftedPoint+mTopLeft;
}
ofPoint simpleWindow::toLocalAxisSystem(ofPoint point){

    ofPushMatrix();
    ofTranslate(mTopLeft);
    point-=mTopLeft;
    ofVec3f origin(0,0,1);
    ofPoint shiftedPoint = point.getRotatedRad(-angle, origin);
    ofPopMatrix();
    return shiftedPoint;
}


void simpleWindow::update(){


    int numGrabs = grabbingCursors.size();

    if (numGrabs == 0)
        setBackgroundColor(ofColor(255, 255, 255, 127));

    if (numGrabs > 0){
        setBackgroundColor(ofColor(255, 0, 0, 127));
        ofPoint topLeftCursor(grabbingCursors[0]->getX()*ofGetWidth() - lastGrabbed.x, grabbingCursors[0]->getY()*ofGetHeight() - lastGrabbed.y);
        setPosition(topLeftCursor);


    if(numGrabs == 2){




        setBackgroundColor(ofColor(255, 255, 0, 127));

        ofPoint currentCursor(grabbingCursors[1]->getX()*ofGetWidth(), grabbingCursors[1]->getY()*ofGetHeight());

        ofVec2f line = mTopLeft - currentCursor;


        //if(ofDist(topLeftCursor.x, topLeftCursor.y, mTopLeft.x, mTopLeft.y) < 20)
           //{
          //  cout << "rotate" << endl;
                        ofSetColor(0,0,255);
            float angleDelta = lastAngle - atan2(line.y, line.x);
        //    cout << "angle Delta is " << angleDelta << endl;
            angle -= angleDelta;
            //cout << "new angle = " << angle << endl << endl;
            lastAngle = atan2(line.y, line.x);


           //}
    //    else{

        //mBottomRight = line;
        scale = ofDist(0,0,line.x,line.y) /lastScale;//
        //scale = 1;


      //  }
                lastScale = ofDist(0,0,line.x,line.y);
        lastPosition = topLeftCursor;
        windowWidth *= scale;
        windowHeight *= scale;
        //   mBottomRight = ofPoint(line.x, line.y);
    }
        lastPosition = mTopLeft;


            }



}



void simpleWindow::draw(){


    ofEnableAlphaBlending();
    ofPushMatrix();
    ofTranslate(mTopLeft);
    ofRotate(ofRadToDeg(angle));
    drawBackground();
    drawGrabbedPoints();
    drawAxis();

    ofPopMatrix();
    ofDisableAlphaBlending();


}



void simpleWindow::drawAxis(){
    ofSetColor(0,0,0, 100);
    ofLine(0, -100, 0, 100);
    ofLine(100, 0, -100, 0);
}

void simpleWindow::drawGrabbedPoints(){
    int numGrabs = grabbingCursors.size();
    ofSetLineWidth(1);
    ofNoFill();

    if(numGrabs >= 1){
        ofSetColor(255, 255, 0);
        ofCircle(0,0, (int)(ofGetElapsedTimef()*30.0)%20);
        ofCircle(0,0, (int)(ofGetElapsedTimef()*30.0)%20 + 4);
        ofCircle(0,0, (int)(ofGetElapsedTimef()*30.0)%20 + 8);
    }
    if(numGrabs == 2){
        ofSetColor(0,0,255);
    }
        ofSetColor(255, 255, 0);
        ofCircle(windowWidth, windowHeight, (int)(ofGetElapsedTimef()*30.0)%20);
        float radius = ofDist(0,0,windowWidth,windowHeight);
        ofSetCircleResolution(200);
        ofCircle(0,0,radius);
}

void simpleWindow::drawBackground(){

    ofSetColor(mBackgroundColor);
    ofNoFill();
//TODO: Make a nicer looking rectangle
    ofSetLineWidth(20);
    ofCircle(0,0,10);
    ofCircle(windowWidth, windowHeight, 10);
    ofFill();
    ofBeginShape();
        ofVertex(0, 0);
        ofVertex(windowWidth, 0);
        ofVertex(windowWidth, windowHeight);
        ofVertex(0, windowHeight);
        ofVertex(0,0);
    ofEndShape();

    }

void simpleWindow::setTuioClient (ofxTuioClient * _tuioClient){
	tuioClient = _tuioClient;

	// HELP with this in order to be independent from the main.
	ofAddListener(tuioClient->cursorAdded,this,&simpleWindow::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&simpleWindow::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&simpleWindow::tuioUpdated);
}

void simpleWindow::tuioAdded(ofxTuioCursor &tuioCursor){
cout << "here" << endl;
    ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());

    if (isOverTopLeft(addedCursor) && grabbingCursors.size() == 0){
        grabbingCursors.push_back(&tuioCursor);
    }
    else if(grabbingCursors.size() == 1 && isOverBottomRight(addedCursor)){
        ofVec2f line =  mTopLeft - addedCursor;
        lastAngle = atan2(line.y, line.x);
        cout << "last angle is " << lastAngle << endl;
        lastScale = ofDist(0, 0, line.x, line.y);
        grabbingCursors.push_back(&tuioCursor);
        }
        else if(containsPoint(addedCursor))
        {
            activeCursor toAdd;
            toAdd.fingerID = tuioCursor.getFingerId();
            toAdd.cursorLoc = toLocalAxisSystem(addedCursor);
            cout << "added active cursor at (local) " << toLocalAxisSystem(addedCursor);
            activeCursors.push_back(toAdd);

        }
}



void simpleWindow::tuioUpdated(ofxTuioCursor &tuioCursor){



}
void simpleWindow::tuioRemoved(ofxTuioCursor &tuioCursor){


    //If this cursor was a part of the menu, remove it from the vector
    for(int i = 0; i < grabbingCursors.size(); i++)
    {

        if (grabbingCursors[i] == &tuioCursor){
//            cout << "removing cursor " << i <<  endl;
            grabbingCursors.erase(grabbingCursors.begin() + i);
        }
    }
        for(int i = 0; i < activeCursors.size(); i++)
    {

        if (activeCursors[i].fingerID == tuioCursor.getFingerId()){
            cout << "removing cursor " << i <<  endl;
            activeCursors.erase(activeCursors.begin() + i);
        }
    }

}

bool simpleWindow::containsPoint(ofPoint point){
    return(point.x > mTopLeft.x - 20
           && point.x < mTopLeft.x + windowWidth + 20
           && point.y > mTopLeft.y - 20
           && point.y < mTopLeft.y + windowHeight + 20);
}

void simpleWindow::setWindowID(int id){
    windowID = id;
}
