#include "testApp.h"

WindowManager mWindowManager;
//--------------------------------------------------------------
void testApp::setup(){
mTuioClient.start(3333);
mWindowManager.initialize(&mTuioClient);
mWindowManager.addWindow(WindowManager::WIN_APP, 200, 200);
}

//--------------------------------------------------------------
void testApp::update(){
    mTuioClient.getMessage();
    mWindowManager.updateWindows();
}

//--------------------------------------------------------------
void testApp::draw(){
    mWindowManager.drawWindows();
    mTuioClient.drawCursors();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
