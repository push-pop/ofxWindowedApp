#ifndef WINAPP_H
#define WINAPP_H

#include "WindowedApp.h"

class winApp : public WindowedApp
{
    public:

    vector <ofxTuioCursor*> grabbingCursors;

    void setup();
    void update();
    void draw();

    ofxTuioClient * tuioClient;

	void    setTuioClient (ofxTuioClient * _tuioClient);

	void	tuioAdded(ofxTuioCursor & tuioCursor);
	void	tuioRemoved(ofxTuioCursor & tuioCursor);
	void	tuioUpdated(ofxTuioCursor & tuioCursor);

    protected:
    private:
};

#endif // WINAPP_H
