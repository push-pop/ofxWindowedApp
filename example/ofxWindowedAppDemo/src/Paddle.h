#ifndef PADDLE_H
#define PADDLE_H

#include "ofxTuio.h"
#include "src/colors.h"

#define HORIZONTAL 0
#define VERTICAL   1

#define MAX_PADDLE_LENGTH 300   // Should be variable dependent upon height of window
#define MIN_PADDLE_LENGTH 50    // dido

class Paddle
{
    public:
        // Constructor
        Paddle();

    // Variables
        // Dimensions
        float topx, topy;                               // Top left corner of button
        float width, height;                            // Dimensions
        int orientation;                                // HORIZONTAL or VERTICAL
        float topEdge, bottomEdge, rightEdge, leftEdge;

        // Visual
        ofColor color, pressedColor, unpressedColor;    // Various colors of button

        // Touch stuff
        bool state;                                     // Clicked or Not
        int cursorID[2];
        ofPoint cursor[2];

        // Game stuff
        bool inPlay;

    // Functions
        // Adds cursor to paddle if (x,y) is on button
        // Returns TRUE if added, FALSE if not
        bool addCursor (float x, float y, int id);

        // Updates the (x,y) of each cursor if cursor has been assigned to button
        bool updateCursor (float x, float y, int id, float wallX, float wallY, float windowWidth, float windowHeight);

        // Adds cursor to paddle if id matches
        // Returns TRUE if removed, FLASE if not
        bool removeCursor (int id);

        // Allows the paddle to be "clicked" on/off
        bool holdPress(float x, float y);

        // Update contact perimeter
        void updateEdges(void);

    protected:
    private:
};

#endif // PADDLE_H
