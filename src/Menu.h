#ifndef MENU_H
#define MENU_H



#include <vector>
#include "Window.h"
#include "MenuItem.h"
#include "ofxTuio.h"
#include "touchEvent.h"
class Menu : public simpleWindow
{
    public:
        Menu();
        ~Menu();

        void addMenuItem(char* label);
        void removeMenuItem(int _position);
        void removeMenuItem(string _label);

        void setXmlFileName(string _xmlFileName);

        void setGrabbed(bool grabbed, ofxTuioCursor &cursor);

        void addCursor(ofxTuioCursor *cursor);
        void draw();
        void update();


            ofxTuioClient * tuioClient;
	void	setTuioClient (ofxTuioClient * _tuioClient);

	void	tuioAdded(ofxTuioCursor & tuioCursor);
	void	tuioRemoved(ofxTuioCursor & tuioCursor);
	void	tuioUpdated(ofxTuioCursor & tuioCursor);



    protected:


        void drawMenuItems();


    private:

        int numMenuItems;


        vector<MenuItem*> mMenuItems;


        string mTitle;
        string xmlFileName;

        float itemHeight;

        ofColor mBackgroundColor;


        static const int DEFAULT_HEIGHT = 500;
        static const int DEFAULT_WIDTH = 700;

        static const int SINGLE_ITEM_HEIGHT = 30;
        static const int MARGIN = 10;
        static const int TEXT_MARGIN = 5;


};

#endif // MENU_H
