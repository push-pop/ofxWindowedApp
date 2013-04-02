#include "testApp.h"
#include "tuioPong.h"
#include "WindowManager.h"
#include "winApp.h"




tuioPong tuioPongApp;
WindowManager mWindowManager;
winApp mWinApp;
Menu mMenu;
//--------------------------------------------------------------
void testApp::setup(){

mTuioClient.start(3333);
mWindowManager.initialize(&mTuioClient);
//mWindowManager.addWindow(&tuioPongApp, 10, 10);
//mWindowManager.addWindow(&mWinApp, 100, 100);
mMenu.addMenuItem("Button 1");
mMenu.addMenuItem("Button 2");
mWindowManager.addWindow(WindowManager::MENU, 500, 500);
//mWindowManager.addWindow(WindowManager::TUIO_PONG, 600, 100);

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
