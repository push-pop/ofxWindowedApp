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
    mFont.loadFont("verdana.ttf", mFontSize);
}

Menu::Menu(ofPoint point) : simpleWindow(point)
{
    windowHeight = DEFAULT_HEIGHT;
    windowWidth = DEFAULT_WIDTH;
    setPosition(point.x, point.y);
    scale = 1.0;
    angle = 0.0;
    lastAngle = 0.0;
    lastScale = 1.0;
    mFont.loadFont("veranda.ttf", mFontSize);
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
//   cout << angle << endl;

    ofRotateZ(ofRadToDeg(angle));
    ofFill();

    itemHeight = windowHeight/mMenuItems.size() - (mMenuItems.size()+1)*MARGIN;
    for(int i = 0; i < mMenuItems.size(); i++)
    {
        ofSetColor(255,0,0,127);
        ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
        ofRectMode(OF_RECTMODE_CORNER);
        ofRect(MARGIN*scale, (i+1)*MARGIN*scale + i*itemHeight, windowWidth - 2*MARGIN, itemHeight);
        ofSetColor(255,255,255, 255);
        mFont.loadFont("verdana.ttf", mFontSize*scale);
        mFont.drawString(mMenuItems[i]->mLabel, MARGIN*scale + TEXT_MARGIN, (i+1)*MARGIN*scale + i*itemHeight + 8*TEXT_MARGIN);
    }
    ofPopMatrix();
}

void Menu::checkMenuItems(){
    //for each menu item
    for(int i=0; i < mMenuItems.size(); i++){
    //check to see if it is selected
/*    if(mMenuItems[i].isSelected)
    {
        mMenuItems[i].executeAction;
    }
*/

}
}


void Menu::setTuioClient (ofxTuioClient * _tuioClient){
	tuioClient = _tuioClient;
	//Sets client for surrounding window
	simpleWindow::setTuioClient(tuioClient);
	//Sets listener for menu items.
	//ofAddListener(tuioClient->cursorAdded,this,&Menu::tuioAdded);
	//ofAddListener(tuioClient->cursorRemoved,this,&Menu::tuioRemoved);
	//ofAddListener(tuioClient->cursorUpdated,this,&Menu::tuioUpdated);
}

void Menu::tuioAdded(ofxTuioCursor &tuioCursor){
	//TODO: Check Menu Items
}
void Menu::tuioUpdated(ofxTuioCursor &tuioCursor){

}
void Menu::tuioRemoved(ofxTuioCursor &tuioCursor){

}

