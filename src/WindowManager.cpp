#include "WindowManager.h"
//#include "../../../apps/myApps/tuioPong/src/tuioPong.h"
#include "winApp.h"
void WindowManager::updateWindows()
{
    for(int i = 0; i < mWindowedApps.size(); i++)
        mWindowedApps[i]->update();

}

void WindowManager::drawWindows()
{
    for(int i = 0; i < mWindowedApps.size(); i++)
        mWindowedApps[i]->draw();

}

void WindowManager::addWindow(windowName nWindow, float x, float y)
{
    switch (nWindow)
    {
    case MENU:
    {

        Menu* newMenu = new Menu();
        newMenu->addMenuItem("Launch Tuio Pong");
        newMenu->addMenuItem("Launch Demo App");
        newMenu->addMenuItem("Exit");
        addWindow(newMenu, x, y);
        break;
    }
    case TUIO_PONG:
    {
//        tuioPong* newTuioPong = new tuioPong();
  //      addWindow(newTuioPong, x, y);
  //      addWindow(newTuioPong, x, y);
        break;
    }
    case WIN_APP:
        winApp* newWinApp = new winApp();
        addWindow(newWinApp, x, y);
    }

}

void WindowManager::addWindow(simpleWindow* nWindow, float x, float y)
{
    mWindowedApps.push_back(nWindow);
    nWindow->setWindowID(mWindowedApps.size() - 1);
    nWindow->setup();
    nWindow->setTuioClient(mTuioClient);
    nWindow->setPosition(x, y);

}


void WindowManager::initialize(ofxTuioClient *_tuioClient)
{
    mTuioClient=_tuioClient;

    //Sets listener
    ofAddListener(mTuioClient->cursorAdded,this,&WindowManager::tuioAdded);
    ofAddListener(mTuioClient->cursorRemoved,this,&WindowManager::tuioRemoved);
    ofAddListener(mTuioClient->cursorUpdated,this,&WindowManager::tuioUpdated);
}

void WindowManager::tuioAdded(ofxTuioCursor & tuioCursor)
{
    //cout << "Tuio Added!" << endl;


}

void WindowManager::tuioUpdated(ofxTuioCursor & tuioCursor)
{
    //cout << "Tuio Updated!" << endl;


}

void WindowManager::tuioRemoved(ofxTuioCursor & tuioCursor)
{
   // cout << "Tuio Removed!" << endl;


}

float WindowManager::distanceToClosestWindow(ofPoint point)
{
    float distance=0;
    for(int i = 0; i < mWindowedApps.size(); i++)
    {
        if(ofDist(point.x, point.y, mWindowedApps[i]->mTopLeft.x, mWindowedApps[i]->mTopLeft.y) > distance)
            distance = ofDist(point.x, point.y, mWindowedApps[i]->mTopLeft.x, mWindowedApps[i]->mTopLeft.y);

    }
    return distance;

}
