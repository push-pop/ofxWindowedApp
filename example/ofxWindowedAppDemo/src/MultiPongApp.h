
#ifndef MULTIPONGAPP_H
#define MULTIPONGAPP_H

#include "WindowedApp.h"
#include "src/Button.h"
#include "src/Paddle.h"
#include "src/colors.h"

#include <string.h>

#define nBalls 4

class MultiPongApp : public WindowedApp
{
    public:
        // Class Functions
        void setup();
        void update();
        void draw();
        void reset();
        void drawBackground();
        void drawPaddles();
        void drawWalls();
        void drawHealth();
        void resetPaddles();
        void removePaddle(int i);

        void drawBall();
        void resetBall(int i);

        void readyPlayState();

        // Class Variables
        vector <ofxTuioCursor*> grabbingCursors;
        GLUquadricObj *quadric;
        ofPoint windowCenter;

        // Skins
        ofImage imPaddleVerticalTouched;
        ofImage imPaddleVerticalNormal;
        ofImage imPaddleHorizontalTouched;
        ofImage imPaddleHorizontalNormal;

        ofImage imBackground;
        ofImage imBackgroundStart;

        ofImage imWallHorizontal;
        ofImage imWallVertical;

        ofImage imHealthVertical;
        ofImage imHealthHorizontal;

        ofImage imBackgroundWin[4];

        ofSoundPlayer sounds[2];

        float score[4]; // Must be a float so division works to the decimal position

        // Scoreboard for displaying the score
        struct Scoreboard {
            float x, y;           // Top left corner of scoreboard (x,y)
            int score[4];       // Used to hold player scores
            string player[4];   // Used to hold player names
            string line;        // Set to "Player: Score"
            ofColor color;      // Scoreboard color
            // Set default values
            Scoreboard()
            {
                for (int i = 0; i < 4; i++)
                    score[i] = 0;
                color = ofColor(255,255,255,0);  // White
            }

        };

        // Pong ball
        struct Ball {
            float radius, xSpd, ySpd;             // Radius and speed of ball
            float left, right, top, bottom;     // Outer edges
            ofPoint center;                     // Center position of circle

            int resetting;

            ofImage image;

            // Set default values
            Ball()
            {
                resetting = 0;
            }
            // Update parameters
            void update()
            {
                left   = center.x - radius;
                right  = center.x + radius;
                top    = center.y - radius;
                bottom = center.y + radius;
            }
        };

        // Use of above structs
        struct Scoreboard mScoreboard;
        struct Ball ball[nBalls];

        // Buttons
        Button centerButton;
        // Paddles
        Paddle paddle[4];   // Clockwise (0 = top, 3 = left)

        // Tuio Functions
        void setTuioClient (ofxTuioClient * _tuioClient);
        void tuioAdded(ofxTuioCursor & tuioCursor);
        void tuioRemoved(ofxTuioCursor & tuioCursor);
        void tuioUpdated(ofxTuioCursor & tuioCursor);
        // Tuio Variables
        ofxTuioClient * tuioClient;
        vector <activeCursor> activeCursors;    // Vector of structs containing a point and an ID

        //ofPoint addedCursor;


    protected:
    private:
};

#endif // MULTIPONGAPP_H
