#pragma once

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "optionGenerator.h"
#include "optionSelector.h"
#include "screenHandle.h"
#include "cursorMovement.h"
#include <vector>

enum Choice {
    MAIN_MENU,
    DEMONSTRATE,
    QUIT,
    TYPING_DEMONASTRATION,
    FREE_TYPING_DEMONSTRATION,
    MOVEMENT_DEMONSTRATION
};

extern int choice;

void processChoice(int chosen);