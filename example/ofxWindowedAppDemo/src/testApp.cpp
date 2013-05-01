#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    mTuioClient.start(3333);
    mWindowManager.initialize(&mTuioClient);    // Setup Listeners
    // Draw Menu
    // Determine Selection
    // Call windows with code below

    //mWindowManager.addWindow(WindowManager::MENU, 300, 100); // Top left corner of app
    mWindowManager.addWindow(WindowManager::SYMMETRY_APP, 300, 200); // Top left corner of app
    //mWindowManager.addWindow(WindowManager::MULTI_PONG_APP, 500, 0); // Top left corner of app

    //mWindowManager.addWindow(WindowManager::KEYBOARD_APP, 0, 0); // Top left corner of app
    //mWindowManager.addWindow(WindowManager::QUIZ_APP, 300, 100); // Top left corner of app
    //mWindowManager.addWindow(WindowManager::WIN_APP, 300, 100); // Top left corner of app
    //mWindowManager.addWindow(WindowManager::NEWSFEED_APP, 300, 100); // Top left corner of app
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
