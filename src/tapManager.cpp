#include "tapManager.h"



bool tapManager::isDoubleTap (ofxTuioCursor currentTap){
    if(lastTap != NULL && tapTimer < 10){
        lastTap = NULL;
        return true;
    }
    lastTap = &currentTap;
    resetTapTimer();
    return false;
}
void tapManager::incrementTimer(){
    tapTimer++;
    if(tapTimer > DOUBLE_TAP_TIME)
    {
        lastTap = NULL;
    }
}

void tapManager::resetTapTimer(){
    tapTimer = 0;
}
