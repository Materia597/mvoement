#pragma once

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <functional>
#include <map>
#include "cursorMovement.h"
#include "screenHandle.h"
#include "optionGenerator.h"
#include "optionSelector.h"

enum ScreenActions {
    SCREEN_START,
    END_SCREEN,
    START_CHOICE,
    CHOICE_MADE,
    END_CHOICE,
    START_TYPING,
    END_TYPING,
    START_FREE_TYPING,
    END_FREE_TYPING,
    START_MOVEMENT,
    END_MOVEMENT,
};

class Screen {

};