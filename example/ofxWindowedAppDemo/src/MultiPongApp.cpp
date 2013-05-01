#include "MultiPongApp.h"

#define CHOOSE_PLAYER   0
#define PLAY            1
#define WIN             2

#define MAX_BALL_SPEED 6
#define MIN_BALL_SPEED 2

#define PADDLE_WIDTH 10     // In reference to the left and right paddles
#define PADDLE_HEIGHT 200    // In reference to the left and right paddles
#define PADDLE_CURVE 5

#define FONT_SIZE 10

#define STARTING_SCORE 10

ofTrueTypeFont mFont;
int state;

int wallWidth;
int wallHeight;
int wallX;
int wallY;

int startnPlayers, currentnPlayers;

void MultiPongApp::setup() {

    ofSetVerticalSync(true);
    //glEnable(GL_DEPTH_TEST);        //enable depth comparisons and update the depth buffer
    //ofDisableArbTex();                //needed for textures to work with gluSphere

    // Load textures
    // Paddles
    imPaddleVerticalTouched.loadImage("Paddle_Textures/vertical_touched.jpg");
    imPaddleVerticalNormal.loadImage("Paddle_Textures/vertical_normal.jpg");
    imPaddleHorizontalTouched.loadImage("Paddle_Textures/horizontal_touched.jpg");
    imPaddleHorizontalNormal.loadImage("Paddle_Textures/horizontal_normal.jpg");

    paddle[0].pressedColor = GREEN;
    paddle[1].pressedColor = RED;
    paddle[2].pressedColor = YELLOW;
    paddle[3].pressedColor = BLUE;

    imBackgroundWin[0].loadImage("Background_Textures/trophy_green.jpg");
    imBackgroundWin[1].loadImage("Background_Textures/trophy_red.jpg");
    imBackgroundWin[2].loadImage("Background_Textures/trophy_yellow.jpg");
    imBackgroundWin[3].loadImage("Background_Textures/trophy_blue.jpg");

    // Background (Start Button in background image)
    imBackgroundStart.loadImage("Background_Textures/start6.jpg");
    imBackground.loadImage("Background_Textures/floor.jpg");

    // Walls
    imWallHorizontal.loadImage("Panel_Textures/horizontal_wood_plank.jpg");
    imWallVertical.loadImage("Panel_Textures/vertical_wood_plank.jpg");

    // Health Bars
    imHealthHorizontal.loadImage("Life_Bar_Texture/horizontal_life_bar.png");
    imHealthVertical.loadImage("Life_Bar_Texture/vertical_life_bar.png");

    // Sounds (throws errors)
    //sounds[0].setVolume(ofRandomuf());
   // sounds[0].loadSound("sound/gamemusic.wav");
    //sounds[0].play();
    //sounds[0].setLoop(1);

    size(500, 500);                             // Window size
    windowCenter = ofPoint(windowWidth/2, windowHeight/2);

    // Ball parameters
    for (int i = 0; i < nBalls; i++) {
        ball[i].resetting = 1;
        ball[i].radius = windowWidth/25;                             // Ball radius
        ball[i].center = ofPoint(ball[i].radius, ball[i].radius, 0);     // Ball starting in top left corner of screen
        ball[i].image.loadImage("sphere.png");
    }

    setPosition(0, 0);                          // Pos of what? ... can be commented out

    // Font
    mFont.loadFont("verdana.ttf", FONT_SIZE);

    // Initial state
    state = CHOOSE_PLAYER;

    // Center Button
    centerButton.width = 0.2*windowWidth;
    centerButton.height = 0.2*windowHeight;
    centerButton.topx = windowWidth/2-centerButton.width/2;
    centerButton.topy = windowHeight/2-centerButton.height/2;
    centerButton.pressedColor   = GREEN;
    centerButton.unpressedColor = WHITE;
    centerButton.color = centerButton.unpressedColor;

    resetPaddles();

    wallWidth = 0.05*windowWidth;
    wallHeight = 0.05*windowHeight;

    wallX = 0.2*windowWidth;
    wallY = 0.2*windowHeight;

    for (int i = 0; i < 4; i++)
        score[i] = STARTING_SCORE;
}

// Update parameters
void MultiPongApp::update() {

    simpleWindow::update();
    WindowedApp::beginDraw();

    // NEED TO ENSURE WIDTH AND HEIGHT ARE WITHIN LIMITS AND IF NECESSARY GUARDING GOAL
    // Update with window
    paddle[1].topx = windowWidth - 2*PADDLE_WIDTH;
    paddle[2].topy = windowHeight - 2*PADDLE_WIDTH;

    // Update paddle edges
    for (int i = 0; i < 4; i++) {
        paddle[i].updateEdges();
        if (paddle[i].inPlay == 0) {
            // Make paddle width = goal width

        }
    }

    if (state == CHOOSE_PLAYER) {
        // Do Nothing
    }
    else if (state == PLAY) {
        // Replaces paddles on goals if window is moved
        for (int i = 0; i < 4; i++) {
            if (paddle[i].inPlay == 0) {
                if(i == 0 || i == 2) {
                    paddle[i].width = windowWidth-wallX*2;
                    paddle[i].topx = wallX;
                }
                else if(i == 1 || i == 3) {
                    paddle[i].height = windowHeight-wallY*2;
                    paddle[i].topy = wallY;
                }
            }
        }


        for (int i = 0; i < nBalls; i++) {
            if (windowWidth > windowHeight)
                ball[i].radius = windowWidth/25;
            else
                ball[i].radius = windowHeight/25;

            ball[i].update(); // Updates left,right,top and bottom parameters

        // Check if ball hits paddle
            // Top paddle
            if (ball[i].top + ball[i].ySpd <= paddle[0].bottomEdge && ball[i].right >= paddle[0].leftEdge && ball[i].left <= paddle[0].rightEdge) {
                if (ball[i].ySpd < 0) {
                    ball[i].ySpd *= -1;
                    if (abs(ball[i].ySpd) < MAX_BALL_SPEED) {
                        ball[i].ySpd *= 1.5;
                    }
                }
            }
            // Bottom paddle
            if (ball[i].bottom + ball[i].ySpd >= paddle[2].topEdge && ball[i].right >= paddle[2].leftEdge && ball[i].left <= paddle[2].rightEdge) {
                if (ball[i].ySpd > 0) {
                    ball[i].ySpd *= -1;
                    if (abs(ball[i].ySpd) < MAX_BALL_SPEED) {
                        ball[i].ySpd *= 1.5;
                    }
                }
            }
            // Left paddle
            if (ball[i].left + ball[i].xSpd <= paddle[3].rightEdge && ball[i].top <= paddle[3].bottomEdge && ball[i].bottom >= paddle[3].topEdge) {
                if (ball[i].xSpd < 0) {
                    ball[i].xSpd *= -1;
                    if (abs(ball[i].xSpd) < MAX_BALL_SPEED) {
                        ball[i].xSpd *= 1.5;
                    }
                }
            }
            // Right paddle
            if (ball[i].right + ball[i].xSpd >= paddle[1].leftEdge && ball[i].top <= paddle[1].bottomEdge && ball[i].bottom >= paddle[1].topEdge) {
                if (ball[i].xSpd > 0) {
                    ball[i].xSpd *= -1;
                    if (abs(ball[i].xSpd) < MAX_BALL_SPEED) {
                        ball[i].xSpd *= 1.5;
                    }
                }
            }

        // Check if ball hits walls
            // Right Wall
            if (ball[i].right + ball[i].xSpd >= windowWidth - wallWidth) {
                if (ball[i].top <= wallY || ball[i].bottom >= windowHeight-wallY) {
                    if (ball[i].xSpd > 0 ) {
                        ball[i].xSpd *= -1;
                        if (ball[i].xSpd > MIN_BALL_SPEED) {
                            ball[i].xSpd *= 0.9;
                        }
                    }
                }
            }
            // Left Wall
            else if (ball[i].left + ball[i].xSpd <= wallWidth) {
                if(ball[i].top <= wallY || ball[i].bottom >= windowHeight-wallY) {
                    if (ball[i].xSpd < 0 ) {
                        ball[i].xSpd *= -1;
                        if (ball[i].xSpd > MIN_BALL_SPEED) {
                            ball[i].xSpd *= 0.9;
                        }
                    }
                }
            }
            // Top wall
            if (ball[i].top + ball[i].ySpd <= wallWidth) {
                if(ball[i].left <= wallX || ball[i].right >= windowWidth-wallX) {
                    if (ball[i].ySpd < 0 ) {
                        ball[i].ySpd *= -1;
                        if (ball[i].ySpd > MIN_BALL_SPEED) {
                            ball[i].ySpd *= 0.9;
                        }
                    }
                }

            }
            // Bottom wall
            else if (ball[i].bottom + ball[i].ySpd >= windowHeight - wallWidth) {
                if(ball[i].left <= wallX || ball[i].right >= windowWidth-wallX) {
                    if (ball[i].ySpd > 0 ) {
                        ball[i].ySpd *= -1;
                        if (ball[i].ySpd > MIN_BALL_SPEED) {
                            ball[i].ySpd *= 0.9;
                        }
                    }
                }
            }

        // Change score if ball is in goal region
            // Check if ball hits right goal
            if (ball[i].right >= (float)windowWidth) {
                // Update Score
                if (score[1] > 0)
                    score[1]--;
                if (score[1] == 0) {
                    removePaddle(1);
                }
                ball[i].resetting = 1;
            }
            // Check if ball hits left goal
            else if (ball[i].left < 0){
                if (score[3] > 0)
                    score[3]--;
                if (score[3] == 0) {
                    removePaddle(3);
                }
                ball[i].resetting = 1;
            }
            // Check if ball hits bottom goal
            else if (ball[i].bottom >= (float)windowHeight){
                if (score[2] > 0)
                    score[2]--;
                if (score[2] == 0) {
                    removePaddle(2);
                }
                ball[i].resetting = 1;
            }
            // Check if ball hits top goal
            else if (ball[i].top < 0){
                if (score[0] > 0)
                    score[0]--;
                if (score[0] == 0) {
                    removePaddle(0);
                }
                ball[i].resetting = 1;
            }

            // Check if balls hit each other
            if (i < nBalls-1) {
                for (int j = i+1; j < nBalls; j++) {
                    if (ofDist(ball[i].center.x, ball[i].center.y, ball[j].center.x, ball[j].center.y) <= ball[i].radius + ball[j].radius) {
                        // Collision Dynamics
                        float dx = ball[j].center.x - ball[i].center.x;
                        float dy = ball[j].center.y - ball[i].center.y;
                        float d = sqrt(dx*dx+dy*dy);

                        float mag1 = sqrt(ball[i].xSpd*ball[i].xSpd + ball[j].ySpd*ball[j].ySpd);
                        float mag2 = sqrt(ball[i].ySpd*ball[i].ySpd + ball[j].xSpd*ball[j].xSpd);

                        ball[j].xSpd = mag1*dx/d;
                        ball[j].ySpd = mag1*dy/d;

                        ball[i].xSpd = -1*mag1*dx/d;
                        ball[i].ySpd = -1*mag1*dy/d;

                        if (ball[i].xSpd < MIN_BALL_SPEED)
                            ball[i].xSpd = MIN_BALL_SPEED;
                        if (ball[i].ySpd < MIN_BALL_SPEED)
                            ball[i].ySpd = MIN_BALL_SPEED;

                    }
                }
            }

        // Update Ball
            if (!ball[i].resetting) {
                ball[i].center.x += ball[i].xSpd;
                ball[i].center.y += ball[i].ySpd;
            }
        }
    }

    WindowedApp::endDraw();
}

void MultiPongApp::reset() {
    // Reset Paddles
    resetPaddles();
    // Reset Balls
    for (int i = 0; i < nBalls; i++) {
        resetBall(i);
    }
    // Reset Scores
    for (int i = 0; i < 4; i++) {
        score[i] = STARTING_SCORE;
    }
    state = CHOOSE_PLAYER;
}

void MultiPongApp::resetBall(int i) {
    // Pick a random corner of the 4
    //int r = ofRandom(0,4);
    if (i == 3)        // Top Left corner
        ball[i].center = ofPoint(wallWidth+ball[i].radius, wallWidth+ball[i].radius);
    else if (i == 2)   // Top Right corner
        ball[i].center = ofPoint(windowWidth-wallWidth-ball[i].radius, wallWidth+ball[i].radius);
    else if (i == 1)   // Bottom Left corner
        ball[i].center = ofPoint(wallWidth+ball[i].radius, windowHeight-wallWidth-ball[i].radius);
    else              // Bottom Right corner
        ball[i].center = ofPoint(windowWidth-wallWidth-ball[i].radius, windowHeight-wallWidth-ball[i].radius);

    // Pick a random velocity
    ball[i].xSpd = ofRandom(MIN_BALL_SPEED, MAX_BALL_SPEED);
    ball[i].ySpd = ofRandom(MIN_BALL_SPEED, MAX_BALL_SPEED);

    // Shoot
    ball[i].resetting = 0;
}

void MultiPongApp::resetPaddles() {
    // Paddles (0 = top, 3 = left)
    paddle[3].height = paddle[1].height = paddle[0].width = paddle[2].width = windowHeight/5;
    paddle[3].width = paddle[1].width = paddle[0].height = paddle[2].height = PADDLE_WIDTH;

    paddle[0].topx = paddle[2].topx = windowWidth/2 - paddle[0].width/2;
    paddle[0].topy = PADDLE_WIDTH;
    paddle[2].topy = windowHeight - 2*PADDLE_WIDTH;

    paddle[1].topy = paddle[3].topy = windowHeight / 2 - paddle[1].height/2;
    paddle[3].topx = PADDLE_WIDTH;
    paddle[1].topx = windowWidth - 2*PADDLE_WIDTH;

    paddle[0].orientation = paddle[2].orientation = HORIZONTAL;
    paddle[1].orientation = paddle[3].orientation = VERTICAL;

    for (int i = 0; i < 4; i++) {
        paddle[i].inPlay = 0;
    }
}

void MultiPongApp::drawBackground() {
    ofSetColor(WHITE);
    if (state == CHOOSE_PLAYER)
        imBackgroundStart.draw(0,0, windowWidth, windowHeight);
    else if (state == PLAY)
        imBackground.draw(0,0, windowWidth, windowHeight);
    else if (state == WIN) {
        for (int i = 0; i < 4; i++) {
            if (paddle[i].inPlay) {
                imBackgroundWin[i].draw(0,0, windowWidth, windowHeight);
                break;
            }
            if (i == 3)
                reset();
        }
    }
}

void MultiPongApp::drawWalls() {
    wallWidth = 0.05*windowWidth;
    wallHeight = 0.05*windowHeight;
    wallX = 0.2*windowWidth;
    wallY = 0.2*windowHeight;

    // Left
    imWallVertical.draw(0,0, wallWidth, wallY);
    imWallVertical.draw(0,windowHeight-wallY, wallWidth, wallY);
    // Right
    imWallVertical.draw(windowWidth-wallWidth,0, wallWidth, wallY);
    imWallVertical.draw(windowWidth-wallWidth,windowHeight-wallY, wallWidth, wallY);
    // Top
    imWallHorizontal.draw(0, 0, wallX, wallHeight);
    imWallHorizontal.draw(windowWidth-wallX, 0, wallX, wallHeight);
    // Bottom
    imWallHorizontal.draw(0, windowHeight-wallHeight, wallX, wallHeight);
    imWallHorizontal.draw(windowWidth-wallX, windowHeight-wallHeight, wallX, wallHeight);

}

void MultiPongApp::drawPaddles() {

    ofSetColor(paddle[0].color);
    if (paddle[0].state == 1) // Being touched
        imPaddleHorizontalTouched.draw(paddle[0].topx, paddle[0].topy, paddle[0].width, paddle[0].height);
    else
        imPaddleHorizontalNormal.draw(paddle[0].topx, paddle[0].topy, paddle[0].width, paddle[0].height);

    ofSetColor(paddle[1].color);
    if (paddle[1].state == 1) // Being touched
        imPaddleVerticalTouched.draw(paddle[1].topx, paddle[1].topy, paddle[1].width, paddle[1].height);
    else
        imPaddleVerticalNormal.draw(paddle[1].topx, paddle[1].topy, paddle[1].width, paddle[1].height);

    ofSetColor(paddle[2].color);
    if (paddle[2].state == 1) // Being touched
        imPaddleHorizontalTouched.draw(paddle[2].topx, paddle[2].topy, paddle[2].width, paddle[2].height);
    else
        imPaddleHorizontalNormal.draw(paddle[2].topx, paddle[2].topy, paddle[2].width, paddle[2].height);

    ofSetColor(paddle[3].color);
    if (paddle[3].state == 1) // Being touched
        imPaddleVerticalTouched.draw(paddle[3].topx, paddle[3].topy, paddle[3].width, paddle[3].height);
    else
        imPaddleVerticalNormal.draw(paddle[3].topx, paddle[3].topy, paddle[3].width, paddle[3].height);
}

void MultiPongApp::drawBall() {
    ofSetColor(WHITE);
    ofEnableAlphaBlending();
    for (int i = 0; i < nBalls; i++) {
        ball[i].image.draw(ball[i].center.x-ball[i].radius, ball[i].center.y-ball[i].radius, ball[i].radius*2, ball[i].radius*2);
    }
}

void MultiPongApp::drawHealth() {
    ofEnableAlphaBlending();

    float bar_width = 0.8*wallWidth;
    float bar_height = 0.7*wallY;
    float x_offset = 0.1*wallWidth;
    float y_offset = 0.1*wallHeight;

    // Left Health Bar
    if (paddle[3].inPlay == 1) {
        ofSetColor(paddle[3].pressedColor);
        ofRect(x_offset, wallWidth, bar_width, bar_height*(score[3]/STARTING_SCORE));
        imHealthVertical.draw(x_offset, wallWidth, bar_width, bar_height);
    }

    // Right Health Bar
    if (paddle[1].inPlay == 1) {
        ofSetColor(paddle[1].pressedColor);
        ofRect(windowWidth-bar_width-x_offset, windowHeight-wallWidth-bar_height, bar_width, bar_height*(score[1]/STARTING_SCORE));
        imHealthVertical.draw(windowWidth-bar_width-x_offset, windowHeight-wallWidth-bar_height, bar_width, bar_height);
    }

    // Top Health Bar
    if (paddle[0].inPlay == 1) {
        ofSetColor(paddle[0].pressedColor);
        ofRect(windowWidth - wallWidth - bar_height, y_offset, bar_height*(score[0]/STARTING_SCORE), bar_width);
        imHealthHorizontal.draw(windowWidth - wallWidth - bar_height, y_offset, bar_height, bar_width);
    }

    // Bottom Health Bar
    if (paddle[2].inPlay == 1) {
        ofSetColor(paddle[2].pressedColor);
        ofRect(wallWidth + x_offset, windowHeight - bar_width - y_offset, bar_height*(score[2]/STARTING_SCORE), bar_width);
        imHealthHorizontal.draw(wallWidth + x_offset, windowHeight - bar_width - y_offset, bar_height, bar_width);
    }
}

void MultiPongApp::draw() {
    WindowedApp::beginDraw();

    ofFill();

    drawBackground();
    drawWalls();
    drawPaddles();
    drawHealth();

    // Ball
    if (state == PLAY) {
        for (int i = 0; i < nBalls; i++) {
            if (ball[i].resetting)
                resetBall(i);
            else
                drawBall();
        }
    }

    WindowedApp::endDraw();
}

void MultiPongApp::removePaddle(int i) {
    // Take out non in play players (Quick patch)
    if(i ==  0 || i == 2) {
        paddle[i].width = windowWidth-wallX*2;
        paddle[i].topx = wallX;
        paddle[i].inPlay = 0;
    }
    else if(i == 1 || i == 3) {
        paddle[i].height = windowHeight-wallY*2;
        paddle[i].topy = wallY;
        paddle[i].inPlay = 0;
    }
    currentnPlayers--;

    if (startnPlayers == 1 && currentnPlayers == 0) {
        state = WIN;
    }
    else if (startnPlayers > 1 && currentnPlayers == 1) {
        state = WIN;
    }
}

void MultiPongApp::readyPlayState() {
    startnPlayers = currentnPlayers = 4;

    for (int i = 0; i < 4; i++) {
        paddle[i].color = paddle[i].unpressedColor;
        paddle[i].inPlay = paddle[i].state;
        if (paddle[i].inPlay == 0) {
                removePaddle(i);
                startnPlayers--;
        }
        paddle[i].state = 0;
    }
}

void MultiPongApp::setTuioClient (ofxTuioClient * _tuioClient){
	tuioClient = _tuioClient;

    //cout << "Hello" << endl;

	//Sets client for surrounding window
	WindowedApp::setTuioClient(tuioClient); // Allows the inheritance class functions to be called as well

	//Sets listener for menu items.
	ofAddListener(tuioClient->cursorAdded,this,&MultiPongApp::tuioAdded);
	ofAddListener(tuioClient->cursorRemoved,this,&MultiPongApp::tuioRemoved);
	ofAddListener(tuioClient->cursorUpdated,this,&MultiPongApp::tuioUpdated);
}

void MultiPongApp::tuioAdded(ofxTuioCursor &tuioCursor){
	//TODO: Check Menu Items

    ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
    addedCursor = toLocalAxisSystem(addedCursor);

    // Possible tuio active cursor to add
    activeCursor toAdd;
    toAdd.fingerID = tuioCursor.getFingerId();
    toAdd.cursorLoc = addedCursor;

    if (state == CHOOSE_PLAYER) {
        // Check click on start button
        if(centerButton.checkPress(addedCursor.x, addedCursor.y, toAdd.fingerID)) {
            readyPlayState();
            state = PLAY;
        }
        else {
            // Check each paddle
            for (int i = 0; i < 4; i++) {
                paddle[i].holdPress(addedCursor.x, addedCursor.y);
            }
        }
    }
    else if (state == PLAY) {
        // Check click on reset button
        if (startnPlayers == 0) {
            if(centerButton.checkPress(addedCursor.x, addedCursor.y, toAdd.fingerID)) {
                reset();
            }
        }
        // Check each paddle only if they are inPlay
        for (int i = 0; i < 4; i++) {
            if (paddle[i].inPlay == 1)
                paddle[i].addCursor(addedCursor.x, addedCursor.y, toAdd.fingerID);
        }

    }
}

void MultiPongApp::tuioUpdated(ofxTuioCursor &tuioCursor){

    ofPoint currentPoint(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
    currentPoint = toLocalAxisSystem(currentPoint);

    activeCursor tuioUpdate;
    tuioUpdate.fingerID = tuioCursor.getFingerId();
    tuioUpdate.cursorLoc = currentPoint;

    if (state == CHOOSE_PLAYER) {

    }
    else if (state == PLAY) {
        // Update Paddles
        for (int i = 0; i < 4; i++) {
            paddle[i].updateCursor(tuioUpdate.cursorLoc.x, tuioUpdate.cursorLoc.y, tuioUpdate.fingerID, wallX, wallY, windowWidth, windowHeight);
        }
    }
    else if (state == WIN) {
        reset();
    }
}

void MultiPongApp::tuioRemoved(ofxTuioCursor &tuioCursor){

    ofPoint addedCursor(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
    addedCursor = toLocalAxisSystem(addedCursor);   // Nope
    int id = tuioCursor.getFingerId();

    if (state == CHOOSE_PLAYER) {
        // Check click on start button
        if(centerButton.checkRelease(tuioCursor.getFingerId())) {
            // Can do something here
        }
    }
    else if (state == PLAY) {

        // Remove cursor from paddles
        for (int i = 0; i < 4; i++) {
            paddle[i].removeCursor(id);
        }

        // Remove cursor from active cursors
        for(int i = 0; i < activeCursors.size(); i++)
        {
            if (activeCursors[i].fingerID == tuioCursor.getFingerId()){
                //cout << "removing cursor " << activeCursors[i].fingerID <<  endl;
                activeCursors.erase(activeCursors.begin() + i);
            }
        }
    }

}
