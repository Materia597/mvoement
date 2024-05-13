#include <conio.h>
#include <iostream>
#include "cursorMovement.h"
#include "main.h"
#include "optionGenerator.h"
#include <vector>

int Cursor::cursorMode = FREE_TYPE;
bool Cursor::control_code_entered = false;

int Cursor::cursorX = 1;
int Cursor::cursorY = 1;

void Cursor::moveCursor(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void Cursor::homeCursor() {
    cursorX = 1;
    cursorY = 1;
    resetCursor();
}

void Cursor::setCursor(int x, int y) {
    cursorX = x;
    cursorY = y;
    moveCursor(cursorX, cursorY);
}

void Cursor::resetCursor() {
    moveCursor(cursorX, cursorY);
}

std::map<Keys, Movement_Directions> arrowsToDirection = {
    {Keys::UP_ARROW, Movement_Directions::Up},
    {Keys::DOWN_ARROW, Movement_Directions::Down},
    {Keys::LEFT_ARROW, Movement_Directions::Left},
    {Keys::RIGHT_ARROW, Movement_Directions::Right}
};

bool Cursor::setCursorMode(int cursorMode) {
    switch(cursorMode) {
        case MOVE:
            Cursor::cursorMode = CursorMode::MOVE;
            break;
        case FREE_TYPE:
            Cursor::cursorMode = CursorMode::FREE_TYPE;
            break;
        case OPTION_SELECT:
            Cursor::cursorMode = CursorMode::OPTION_SELECT;
            break;
        case TYPE:
            Cursor::cursorMode = CursorMode::TYPE;
            break;
        default:
            return false;
    }
    return true;
}

int Cursor::getCursorMode() {
    return cursorMode;
}

bool Cursor::startCursorMode(char key) {
    switch(cursorMode) {
        case MOVE:
            if(detectEnter(key)) {
                return true;
            }
            cursorMove(key);
            break;
        case FREE_TYPE:
            return freeTyping(key);
            break;
        case OPTION_SELECT:
            break;
        case TYPE:
            return typing(key);
            break;
        default:
            break;
    }
    return false;
}


void Cursor::cursorMove(char key) {
    switch(key) {
        case UP_ARROW:
        case DOWN_ARROW:
        case LEFT_ARROW:
        case RIGHT_ARROW:
            cursorMoveDirection(arrowsToDirection[(Keys)key], 1);
            break;
        case BACKSPACE:
            if(Cursor::cursorMode == TYPE || Cursor::cursorMode == FREE_TYPE) {
                cursorMoveDirection(Left, 1);
            }
            break;
        case DELETE:
            if(Cursor::cursorMode == TYPE || Cursor::cursorMode == FREE_TYPE) {
                cursorMoveDirection(Right, 1);
            }
            break;
        default:
            break;
    }
}

void Cursor::cursorMoveDirection(int direction, int quantity) {
    if(quantity > 1) return;
    
    switch(direction) {
        case Movement_Directions::Up:
            if(cursorY - quantity > 1) {
                cursorY -= quantity;
            } else cursorY = 1;
            break;
        case Movement_Directions::Down:
            if(cursorY + quantity < screenRows) {
                cursorY += quantity;
            } else cursorY = screenRows;
            break;
        case Movement_Directions::Left:
            if(cursorX - quantity > 1) {
                cursorX -= quantity;
            } else cursorX = 1;
            break;
        case Movement_Directions::Right:
            if(cursorX + quantity < screenColumns) {
                cursorX += quantity;
            } else cursorX = screenColumns;
            break;
        default:
            return;
            break;
    }

    resetCursor();
}



//a return value of true means that the quitKey was pressed
bool Cursor::cursorMoveWithCancel(char quitKey = 'q') {
    char key = _getch();

    if(key == quitKey) {
        return true;
    }
    cursorMove(key);
    return false;
}

//a return value of true meand that the quitKey was pressed
bool Cursor::cursorMoveWithCancel(char key, char quitKey) {
    if(key == quitKey) {
        return true;
    }


    cursorMove(key);
    return false;
}

bool Cursor::detectEnter(char key) {
    return (key == '\n' || key == '\r');
}

void Cursor::typeLetter(char key) {
    if(control_code_entered) {
        return;
    }

    if(cursorX < screenColumns) {
        std::cout << key;
        cursorX++;
    }
}

void Cursor::specialKeyAction(char key) {
    switch(key) {
        case DELETE:
        case BACKSPACE:
            std::cout << " ";
            break;
        default:
            break;
    }
}

//a return value of true means that the typing should stop
//function used when the user can type in any location on the screen
bool Cursor::freeTyping(char key) {
    
    if(detectEnter(key)) {
        return true;
    }

    switch(key) {
        
        case ARROW_CONTROL_KEY:
            control_code_entered = true;
            break;
        case BACKSPACE:
            specialKeyAction(key);
            cursorMove(key);
            break;
        case UP_ARROW:
        case DOWN_ARROW:
        case LEFT_ARROW:
        case RIGHT_ARROW:
        case DELETE:
            //std::cout << " ";
            if(!control_code_entered) {
                typeLetter(key);
            }
            specialKeyAction(key);
            cursorMove(key);
            control_code_entered = false;
            break;
            
        default:
            typeLetter(key);
            break;
    }

    return false;
}

//a return value of true means the enter key was pressed
//function used when the user can only type in a specific location
//bounds should be placed on the amount the user can move left and right
bool Cursor::typing(char key) {

    if(detectEnter(key)) {
        return true;
    }

    switch(key) {
        case ARROW_CONTROL_KEY:
            control_code_entered = true;
            break;
        case BACKSPACE:
            specialKeyAction(key);
            cursorMove(key);
            break;
        case LEFT_ARROW:
        case RIGHT_ARROW:
        case DELETE:
            if(!control_code_entered) {
                typeLetter(key);
            }
            specialKeyAction(key);
            cursorMove(key);
            control_code_entered = false;
            break;
        default:
            typeLetter(key);
            break;
    }

    return false;
}