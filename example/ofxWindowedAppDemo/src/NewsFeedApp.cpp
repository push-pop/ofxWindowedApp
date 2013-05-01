#include "NewsFeedApp.h"

void NewsFeedApp::setup() {
    //cout << "NewsFeedApp Setup" << endl;
    // Your setup code here...
    size(500, 500);                             // Window size


}

void NewsFeedApp::update() {
    //cout << "NewsFeedApp update" << endl;
    simpleWindow::update();
    WindowedApp::beginDraw();
    // Your update code here...



    WindowedApp::endDraw();
}

void NewsFeedApp::draw() {
    //cout << "NewsFeedApp draw" << endl;
    WindowedApp::beginDraw();
    // Your draw code here...



    WindowedApp::endDraw();

}
