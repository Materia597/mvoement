#pragma once

#ifndef CURSOR_MOVEMENT
#define CURSOR_MOVEMENT

#include <conio.h>
#include <iostream>
//#include "optionGenerator.h"
#include <vector>
#include <map>

enum CursorMode {
    MOVE,
    FREE_TYPE,
    OPTION_SELECT,
    TYPE
};

enum Keys {
    ARROW_CONTROL_KEY = -32,

    BACKSPACE = 8,
    DELETE = 83,
    
    UP_ARROW = 72,
    DOWN_ARROW = 80,
    LEFT_ARROW = 75,
    RIGHT_ARROW = 77
};

enum Movement_Directions {
    Up,
    Down,
    Left,
    Right
};

class Cursor {

private:
    static int cursorMode;
    static bool control_code_entered;

    static const int screenColumns = 160;
    static const int screenRows = 48;

    static int cursorX;
    static int cursorY;

    static void cursorMove(char key);
    static void cursorMoveDirection(int direction, int quantity);
    static bool cursorMoveWithCancel(char quitkey);
    static bool cursorMoveWithCancel(char key, char quitkey);
    
    static void specialKeyAction(char key);
    static void typeLetter(char key);

    static bool freeTyping(char key);
    static bool typing(char key); 

public:
    static void homeCursor();
    static void moveCursor(int x, int y);
    static void setCursor(int x, int y);
    static void resetCursor();
    static bool setCursorMode(int cursorMode);
    static int getCursorMode();
    static bool startCursorMode(char key);

    static bool detectEnter(char key);

};

#endif