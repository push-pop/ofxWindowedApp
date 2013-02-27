#ifndef WINDOWEDAPP_H
#define WINDOWEDAPP_H

#include "Window.h"
class WindowedApp : public simpleWindow
{
    public:
        WindowedApp() : simpleWindow() {}
        virtual ~WindowedApp() {}



        void setup();
        void update(){simpleWindow::update();};
        void draw();

        void size(float width, float height);

        void beginDraw();
        void endDraw();


            ofxTuioClient * tuioClient;
	void	setTuioClient (ofxTuioClient * _tuioClient);

	void	tuioAdded(ofxTuioCursor & tuioCursor);
	void	tuioRemoved(ofxTuioCursor & tuioCursor);
	void	tuioUpdated(ofxTuioCursor & tuioCursor);

    protected:
    private:
};

#endif // WINDOWEDAPP_H
