#include "Menu.h"

Menu::Menu() : simpleWindow()
{
    windowHeight = DEFAULT_HEIGHT;
    windowWidth = DEFAULT_WIDTH;
    setPosition(200,200);
    scale = 1.0;
    angle = 0.0;
    lastAngle = 0.0;
    lastScale = 1.0;



    }



Menu::~Menu()
{
    //dtor
    cout << "destructing Menu" << endl;
    for (int i = 0; i < mMenuItems.size(); i++)
        delete mMenuItems[i];
    mMenuItems.clear();

}



void Menu::addMenuItem(char* label){

    MenuItem* temp = new MenuItem(label, mTopLeft);
    mMenuItems.push_back(temp);
}

void Menu::removeMenuItem(int _position){
    mMenuItems.erase(mMenuItems.begin() + _position);
    numMenuItems--;
    }
void Menu::addCursor(ofxTuioCursor *cursor){
    grabbingCursors.push_back(cursor);
}

void Menu::update(){
    simpleWindow::update();


}

void Menu::draw(){
    simpleWindow::draw();
    drawMenuItems();

}


void Menu::drawMenuItems(){


    ofPushMatrix();
    ofTranslate(mTopLeft);
//    cout << angle << endl;

    ofRotateZ(ofRadToDeg(angle));
    ofFill();

    itemHeight = windowHeight/mMenuItems.size() - (mMenuItems.size()+1)*MARGIN;
    for(int i = 0; i < mMenuItems.size(); i++)
    {
            ofSetColor(255,0,0,127);

        ofRectMode(OF_RECTMODE_CORNER);
        ofRect(MARGIN*scale, (i+1)*MARGIN*scale + i*itemHeight, windowWidth - 2*MARGIN, itemHeight);
        ofSetColor(255,255,255, 255);
        ofDrawBitmapString(mMenuItems[i]->mLabel, MARGIN*scale + TEXT_MARGIN, (i+1)*MARGIN*scale + i*itemHeight + 2*TEXT_MARGIN);

    }
    ofPopMatrix();
}


void Menu::setTuioClient (ofxTuioClient * _tuioClient){
	tuioClient = _tuioClient;
	//Sets client for surrounding window
	simpleWindow::setTuioClient(tuioClient);
	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&Menu::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&Menu::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&Menu::tuioUpdated);
}


void Menu::tuioAdded(ofxTuioCursor &tuioCursor){
	//TODO: Check Menu Items



}
void Menu::tuioUpdated(ofxTuioCursor &tuioCursor){


}
void Menu::tuioRemoved(ofxTuioCursor &tuioCursor){



}

