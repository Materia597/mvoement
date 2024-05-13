#include <iostream>
#include <conio.h>
#include <vector>
#include <stdio.h>
#include "optionGenerator.h"
#include "cursorMovement.h"
#include "optionSelector.h"

/*
Options OptionInformation::currentOption;
std::vector<int> OptionInformation::lineNumbers;
int OptionInformation::currentLineIndex;
*/

OptionInformation::OptionInformation(Options currentOption, std::vector<int> lineNumber, int currentLineIndex)
    : currentOption(currentOption), lineNumbers(lineNumber), currentLineIndex(currentLineIndex) {};

bool OptionInformation::optionSelect(char key) {
    Cursor::moveCursor(1, OptionInformation::lineNumbers[OptionInformation::currentLineIndex]);

    if(Cursor::detectEnter(key)) {
        return true;
    }

    switch(key) {
        case UP_ARROW:
            OptionInformation::currentLineIndex--;
            break;
        case DOWN_ARROW:
            OptionInformation::currentLineIndex++;
            break;
        default:
            return false;
    }
    OptionInformation::currentLineIndex = OptionInformation::currentLineIndex % OptionInformation::lineNumbers.size();

    Cursor::moveCursor(1, OptionInformation::lineNumbers[OptionInformation::currentLineIndex]);

    return false;
}

std::string OptionInformation::getOptionText() {
    return OptionInformation::currentOption.getOptionText(OptionInformation::currentLineIndex);
}

int OptionInformation::getOptionNumber() {
    return OptionInformation::currentOption.getOptionNumber(OptionInformation::currentLineIndex);
}

option OptionInformation::selectOption() {
    char key;

    OptionInformation::currentLineIndex = 0;
    Cursor::moveCursor(1,OptionInformation::lineNumbers[OptionInformation::currentLineIndex]);

    while(true) {
        key = _getch();
        if(OptionInformation::optionSelect(key)) {
            break;
        }
    }

    Cursor::resetCursor();

    int lineOffset = OptionInformation::lineNumbers[OptionInformation::currentLineIndex] - OptionInformation::currentOption.optionLineNumber;

    return option(OptionInformation::getOptionNumber(), OptionInformation::getOptionText(), lineOffset);

}




OptionInformation OptionInformation::OptionInformationBuilder(Options option) {
    return OptionInformation(option, option.getOptionLineNumbers(), option.getOptionLineNumbers().size());
}