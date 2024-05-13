#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "cursorMovement.h"
#include "screenHandle.h"
#include "optionGenerator.h"
#include "optionSelector.h"
#include "choiceHandler.h"


void handleOptionSelection(OptionInformation optionSelect) {
    std::string optionText = optionSelect.getOptionText();
    if(optionText == "Option 1") {
        Cursor::moveCursor(20, 3);
        std::cout << "You Chose Option 1";
    }
}


int main() {
    ScreenHandler::begin_program();


    while(true) {
        processChoice(choice);

        if(choice == QUIT) {
            ScreenHandler::clearScreen();
            return 0;
        }
    }

    return 0;
}