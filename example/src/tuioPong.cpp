#include "src/tuioPong.h"
    ofPoint puckPos;
    ofVec2f puckVel;
    float puckRad;


    ofPoint player1Pos;
    ofPoint player2Pos;

    int player1Score;
    int player2Score;

    float startHeight = 800;








void tuioPong::setup(){
    setSize(800, 600);

    ofSetRectMode(OF_RECTMODE_CENTER);

    puckPos = ofPoint(windowWidth/2, windowHeight/2);
    //puckVel = ofVec2f(ofRandom(-3, 3), ofRandom(0, 0));
    puckVel = ofVec2f(4, 0);
    puckRad = 20;

    player1Pos = ofPoint(20, windowHeight/2);
    player2Pos = ofPoint(windowWidth-20, windowHeight/2);

    player1Score = 0;
    player2Score = 0;

    resetPuck();
}
void tuioPong::update(){
 beginDraw();
    simpleWindow::update();


    puckPos += puckVel;

    if( puckHitPaddle() ) puckVel.x*=-1;
    if( puckHitHorizWall() ) puckVel.y*=-1;
    if( puckHitVertWall() == 0 ){
        player1Score += 1;
        cout << "player 1 score is now " << player1Score << endl;
        resetPuck();
        }
    else if ( puckHitVertWall() == 1 ){
        player2Score += 1;
        cout << "player 2 score is now " << player2Score << endl;
        resetPuck();
        }

        endDraw();

}

void tuioPong::draw(){
    beginDraw();
    ofRect(player1Pos, 40, 100);
    ofRect(player2Pos, 40, 100);
    ofCircle(puckPos, puckRad);


    endDraw();

}


bool tuioPong::puckHitPaddle(){
    if (ABS(puckPos.x-puckRad - player1Pos.x) < 20 && ABS(puckPos.y - player1Pos.y) < 50)
        return true;
    else if (ABS(puckPos.x+puckRad - player2Pos.x) < 20 && ABS(puckPos.y - player2Pos.y) < 50)
        return true;
    else
        return false;
}

bool overPaddle(ofPoint point){
        if (ABS(point.x-puckRad - player1Pos.x) < 20 && ABS(point.y - player1Pos.y) < 50)
        return true;
    else if (ABS(point.x+puckRad - player2Pos.x) < 20 && ABS(point.y - player2Pos.y) < 50)
        return true;
    else
        return false;

}

bool tuioPong::puckHitHorizWall(){
    return (puckPos.y > windowHeight-puckRad || puckPos.y < puckRad);

}

int tuioPong::puckHitVertWall(){
    if (puckPos.x > windowWidth-puckRad)
        return 0;
    else if (puckPos.x < puckRad)
        return 1;
    else return -1;

}

void tuioPong::resetPuck(){
        puckPos = ofPoint(windowWidth/2, windowHeight/2);
    puckVel = ofVec2f(ofRandom(2, 3), ofRandom(2, 3));
    puckRad = 20;

}

void tuioPong::setTuioClient (ofxTuioClient * _tuioClient){
	tuioClient = _tuioClient;
	//Sets client for surrounding window
	WindowedApp::setTuioClient(tuioClient);
	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&tuioPong::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&tuioPong::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&tuioPong::tuioUpdated);
}

void tuioPong::tuioAdded(ofxTuioCursor &tuioCursor){
    ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
    ofPoint cursor = toLocalAxisSystem(addedCursor);

    if (overPaddle(cursor))
        {
            player1Pos.y = cursor.y;
            player2Pos.y = cursor.y;

        }


}

void tuioPong::tuioUpdated(ofxTuioCursor &tuioCursor){
        ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
    ofPoint cursor = toLocalAxisSystem(addedCursor);


            player1Pos.y = cursor.y;
            player2Pos.y = cursor.y;




}

void tuioPong::tuioRemoved(ofxTuioCursor &tuioCursor){

}


