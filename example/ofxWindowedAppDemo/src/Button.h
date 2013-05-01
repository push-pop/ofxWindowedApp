#ifndef BUTTON_H
#define BUTTON_H

#include "WindowedApp.h"    // for ofColor

class Button
{
    public:
        // Constructors
        Button();
        Button(float topx, float topy, float width, float height);
        Button(float x, float y, float w, float h, ofColor pressed, ofColor npressed);

        // Variables
        float topx, topy;                               // Top left corner of button
        float width, height;                            // Dimensions
        ofColor color, pressedColor, unpressedColor;    // Various colors of button

        int clickID;                                    // Cursor ID
        bool state;

        // Functions

        // Description: Checks if cursor is within button dimensions
        //  If yes, button is assigned the cursor id, changes color to pressedColor and returns TRUE
        //  else returns FALSE
        bool checkPress(float x, float y, int id);

        // Description: Checks if cursor id is assigned to button
        //  If yes, removes id from button, changes color to unpressedColor and returns TRUE
        //  else returns FALSE
        bool checkRelease(int id);

        // Description: Checks if cursor is within button dimensions
        //  If yes, buttons changes colors from pressedColor to unpressedColor indicating selected/deselected
        bool holdPress(float x, float y);

    protected:
    private:
};

#endif // BUTTON_H
