#include "Paddle.h"

Paddle::Paddle()
{
    topx = topy = width = height = 0;
    pressedColor = BLUE;
    unpressedColor = WHITE;
    state = inPlay = 0;
    cursorID[0] = cursorID[1] = -1;
}


bool Paddle::addCursor(float x, float y, int id) {
    if (x >= topx && x <= (topx + width) ) {
        if (y >= topy && y <= (topy + height)) {
            if (cursorID[0] == -1) {
                cursorID[0] = id;
                cursor[0] = ofPoint(x, y);
                color = pressedColor;
                state = 1;
                return 1;
            }
            else if (cursorID[1] == -1) {
                cursorID[1] = id;
                cursor[1] = ofPoint(x,y);
                return 1;
            }
        }
    }
    else {
        return 0;
    }
}

bool Paddle::updateCursor (float x, float y, int id, float wallX, float wallY, float windowWidth, float windowHeight) {
    if (cursorID[0] == id) {
        // Update Position
        if (orientation == HORIZONTAL) {
            topx += x - cursor[0].x;
            // Stay within bounds
            if (topx < wallX)
                topx = wallX;
            if (topx + width > windowWidth-wallX)
                topx = windowWidth-wallX-width;
        }
        else {  // orientation = VERTICAL
            topy += y - cursor[0].y;
            // Stay within bounds
            if (topy < wallY)
                topy = wallY;
            if (topy + height > windowHeight-wallY)
                topy = windowHeight-wallY-height;
        }
        // Update cursor position
        cursor[0] = ofPoint(x,y);
        return 1;
    }
    else if (cursorID[1] == id) {
        // Update cursor
        cursor[1] = ofPoint(x,y);
        // Update dimensions
        if (orientation == HORIZONTAL) {
            width = abs(cursor[0].x - cursor[1].x);
            // Stay within paddle dimensions
            if (width > MAX_PADDLE_LENGTH)
                width = MAX_PADDLE_LENGTH;
            else if (width < MIN_PADDLE_LENGTH)
                width = MIN_PADDLE_LENGTH;
            // Stay within window dimensions
            if (topx + width > windowWidth-wallX)
                width = windowWidth-wallX-topx;
        }
        else {  // orientation = VERTICAL
            height = abs(cursor[0].y - cursor[1].y);
            // Stay within paddle dimensions
            if (height > MAX_PADDLE_LENGTH)
                height = MAX_PADDLE_LENGTH;
            else if (height < MIN_PADDLE_LENGTH)
                height = MIN_PADDLE_LENGTH;
            // Stay within window dimensions
            if (topy + height > windowHeight-wallY)
                height = windowHeight-wallY-topy;
        }
        return 1;
    }

    return 0;
}

bool Paddle::removeCursor (int id) {
    if (cursorID[0] == id) {
        cursorID[0] = -1;
        color = unpressedColor;
        state = 0;
        return 1;
    }
    else if (cursorID[1] == id) {
        cursorID[1] = -1;
        return 1;
    }
}


bool Paddle::holdPress(float x, float y) {
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

void Paddle::updateEdges(void) {
    leftEdge = topx;
    rightEdge = topx + width;
    topEdge = topy;
    bottomEdge = topy + height;
}
