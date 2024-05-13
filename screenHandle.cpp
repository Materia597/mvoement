

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <map>
#include <string>
#include "cursorMovement.h"
#include "screenHandle.h"
#include "optionGenerator.h"
#include "optionSelector.h"
#include "choiceHandler.h"
#include <fstream>

std::map<Screens, std::string> screenPaths = {
    {Screens::MAIN_MENU_SCREEN, "screens/main menu.txt"},
    {Screens::MOVEMENT_DEMONSTRATION_SCREEN, "screens/movement.txt"}
};

int ScreenHandler::currentScreen = Screens::MAIN_MENU_SCREEN;

void ScreenHandler::changeScreen(int newScreen) {
    std::cout << screenPaths[(Screens)newScreen];
}

void ScreenHandler::displayScreen(int screen) {
    clearScreen();
    std::ifstream file(screenPaths[(Screens)screen]);
    std::string line;

    if(file.is_open()) {
        while(std::getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }

    Cursor::resetCursor();
}

void ScreenHandler::clearScreen() {
    std::cout << "\033[2J\033[1:1H";
}

void ScreenHandler::begin_program() {
    Cursor::resetCursor();
    displayScreen(MAIN_MENU_SCREEN);

    Options exampleOption(10);
    exampleOption.addOption(option(1, "Go To Demonstration", 0));
    exampleOption.addOption(option(2, "Quit", 1));
    exampleOption.displayOptions();

    char key;

    OptionInformation exampleOptionSelect = OptionInformation::OptionInformationBuilder(exampleOption);
    option resultingOption = exampleOptionSelect.selectOption();

    std::cout << "Processed Choice" << std::endl;

    switch(resultingOption.optionNumber) {
        case 1:
            choice = Choice::DEMONSTRATE;
            break;
        case 2:
            choice = Choice::QUIT;
            break;
    }
}


void ScreenHandler::showMainMenu() {
    Cursor::resetCursor();
    displayScreen(MAIN_MENU_SCREEN);
}

void ScreenHandler::showDemonstration() {
    Cursor::setCursor(1,1);
    clearScreen();

    Options demonstrationOption(2);
    demonstrationOption.addOption(option(1, "Typing", 0));
    demonstrationOption.addOption(option(2, "Free Typing", 2));
    demonstrationOption.addOption(option(3, "Movement", 4));
    demonstrationOption.addOption(option(4, "Main Menu", 8));
    demonstrationOption.displayOptions();

    char key;

    OptionInformation demonstationSelect = OptionInformation::OptionInformationBuilder(demonstrationOption);
    option chosen = demonstationSelect.selectOption();

    switch(chosen.optionNumber) {
        case 1:
            choice = Choice::TYPING_DEMONASTRATION;
            break;
        case 2:
            choice = Choice::FREE_TYPING_DEMONSTRATION;
            break;
        case 3:
            choice = Choice::MOVEMENT_DEMONSTRATION;
            break;
        case 4:
            choice = Choice::MAIN_MENU;
            break;
    }
}

void ScreenHandler::gotoTypingDemonstration() {
    Cursor::setCursor(1,1);
    clearScreen();
    Cursor::setCursorMode(TYPE);
    char key;
    while(true) {
        key = _getch();
        if(Cursor::startCursorMode(key)) {
            break;
        }
    }
    choice = DEMONSTRATE;
}

void ScreenHandler::gotoFreeTypingDemonstration() {
    Cursor::setCursor(1,1);
    clearScreen();
    Cursor::setCursorMode(FREE_TYPE);
    char key;
    while(true) {
        key = _getch();
        if(Cursor::startCursorMode(key)) {
            break;
        }
    }
    choice = DEMONSTRATE;
}

void ScreenHandler::gotoMovementDemonstation() {
    Cursor::setCursor(1,1);
    clearScreen();
    displayScreen(MOVEMENT_DEMONSTRATION_SCREEN);
    Cursor::setCursorMode(MOVE);
    char key;
    while(true) {
        key = _getch();
        if(Cursor::startCursorMode(key)) {
            break;
        }
    }
    choice = DEMONSTRATE;
}