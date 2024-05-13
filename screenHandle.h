#pragma once

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "cursorMovement.h"
#include "optionGenerator.h"

enum Screens {
    MAIN_MENU_SCREEN,
    DEMONSTRATION,
    MOVEMENT_DEMONSTRATION_SCREEN
};

class ScreenHandler {
    public:

    static int currentScreen;

    static void changeScreen(int newScreen);
    static void displayScreen(int screen);
    static void clearScreen();

    static void begin_program();
    static void showMainMenu();
    static void showDemonstration();

    static void gotoTypingDemonstration();
    static void gotoFreeTypingDemonstration();
    static void gotoMovementDemonstation();
};