#include "Button.h"
#include "colors.h"
#include "ofMain.h"

Button::Button()
{
    topx = topy = width = height = 0;
    pressedColor = BLUE;
    unpressedColor = WHITE;
    clickID = -1;
    state = 0;
}

Button::Button(float x, float y, float w, float h)
{
    topx = x;
    topy = y;
    width = w;
    height = h;

    pressedColor = BLUE;
    unpressedColor = WHITE;

    clickID = -1;
    state = 0;
}

Button::Button(float x, float y, float w, float h, ofColor pressed, ofColor npressed)
{
    topx = x;
    topy = y;
    width = w;
    height = h;

    pressedColor = pressed;
    unpressedColor = npressed;

    clickID = -1;
    state = 0;
}

bool Button::checkPress(float x, float y, int id)
{
    if (x >= topx && x <= (topx + width) && y >= topy && y <= (topy + height)) {
        clickID = id;
        color = pressedColor;
        state = 1;
        return 1;
    }
    else {
        return 0;
    }
}

bool Button::checkRelease(int id)
{
    if (clickID == id) {
        clickID = -1;
        color = unpressedColor;
        state = 0;
        return 1;
    }
    else
        return 0;
}

bool Button::holdPress(float x, float y)
{
    if (x >= topx && x <= (topx + width) && y >= topy && y <= (topy + height)) {
        if (color == pressedColor) {
            color = unpressedColor;
            state = 0;
        }
        else {
            color = pressedColor;
            state = 1;
        }
        return 1;
    }
    else {
        return 0;
    }
}
