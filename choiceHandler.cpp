#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "optionGenerator.h"
#include "optionSelector.h"
#include "screenHandle.h"
#include "cursorMovement.h"
#include "choiceHandler.h"
#include <vector>

int choice;

void processChoice(int chosen) {
    switch(chosen) {
        case MAIN_MENU:
            ScreenHandler::begin_program();
            break;
        case DEMONSTRATE:
            ScreenHandler::showDemonstration();
            break;
        case QUIT:
            choice = QUIT;
            return;
            break;
        case TYPING_DEMONASTRATION:
            ScreenHandler::gotoTypingDemonstration();
            break;
        case FREE_TYPING_DEMONSTRATION:
            ScreenHandler::gotoFreeTypingDemonstration();
            break;
        case MOVEMENT_DEMONSTRATION:
            ScreenHandler::gotoMovementDemonstation();
            break;
    }
}