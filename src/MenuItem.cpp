#include "MenuItem.h"


MenuItem::MenuItem(string _label, ofPoint topLeft) : simpleWindow(){
    cout << "New menu Item" << endl;
    mLabel = _label;
    mBackgroundColor = ofColor(0,0,255);
//    setPosition(mTopLeft - ITEM_MARGIN, mTopLeft - ITEM_MARGIN);
    windowHeight = ITEM_HEIGHT;
    windowWidth = ITEM_WIDTH;




}



MenuItem::MenuItem(){}
MenuItem::~MenuItem()
{
    //dtor
    cout << "Destroying Menu Item" << endl;
}


string MenuItem::getLabel(){
        return mLabel;
}

void MenuItem::draw(){

    simpleWindow::draw();


}


