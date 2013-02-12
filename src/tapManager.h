#ifndef TAPMANAGER_H
#define TAPMANAGER_H

#include "stddef.h"
#include "testApp.h"

#include "ofxTuio.h"
class tapManager
{

    public:

    tapManager(){};
    ofxTuioCursor* lastTap;
        bool isDoubleTap (ofxTuioCursor currentTap);
        void resetTapTimer();
        void incrementTimer();

    protected:

    private:
    const static int DOUBLE_TAP_TIME = 5;
    unsigned int tapTimer;
};

#endif // TAPMANAGER_H
