#include <iostream>
#include <conio.h>
#include <stdio.h>

#include <map>
#include <functional>
#include <utility>


#include "cursorMovement.h"
#include "screenHandle.h"
#include "optionGenerator.h"
#include "optionSelector.h"
#include "choiceHandler.h"
#include "screen.h"

/*
std::map< std::pair<ScreenActions, int>, std::function<void()>> somethingIDK;

auto func1 = []() {std::cout << "Option 1";};
auto func2 = []() {std::cout << "Option 2";};

somethingIDK[{ScreenActions::SCREEN_START, 1}] = func1;
somethingIDK[{ScreenActions::SCREEN_START, 2}] = func2;

somethingIDK[{ScreenActions::SCREEN_START, 1}]();
std::cout << std::endl;
somethingIDK[{ScreenActions::SCREEN_START, 2}]();
*/

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