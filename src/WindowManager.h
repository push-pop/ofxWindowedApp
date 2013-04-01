#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "ofxTuio.h"
#include "WindowedApp.h"
#include "Menu.h"



class WindowManager
{
public:

    enum windowName
    {
        MENU,
        /* YOUR APPS HERE*/
        WIN_APP,
        TUIO_PONG,
        DEMO_APP
    };

    void initialize(ofxTuioClient *_tuioClient);
    void updateWindows();
    void drawWindows();
    void addWindow(windowName nWindow, float x, float y);
    void addWindow(simpleWindow* nWindow, float x, float y);
    //      void addWindow(Menu _menu);

protected:
    float distanceToClosestWindow(ofPoint point);


private:
    ofxTuioClient *mTuioClient;

    void	tuioAdded(ofxTuioCursor & tuioCursor);
    void	tuioRemoved(ofxTuioCursor & tuioCursor);
    void	tuioUpdated(ofxTuioCursor & tuioCursor);

    //Window Containers
    vector <simpleWindow *> mWindowedApps;
    vector <Menu> mMenus;

};

#endif // WINDOWMANAGER_H
