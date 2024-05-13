
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <map>
#include "cursorMovement.h"
#include <vector>
#include "optionGenerator.h"

option::option(int optionNumber, std::string optionText, int lineOffset)
    : optionNumber(optionNumber), optionText(optionText), lineOffset(lineOffset) {};



Options::Options(int lineNumber) : optionLineNumber(lineNumber) {};

void Options::addOption(option newOption) {
    this->optionList.push_back(newOption);
};

void Options::displayOptions() {
    int baseLine = this->optionLineNumber;
    Cursor::moveCursor(1,baseLine);

    for(option currentOption : optionList) {
        Cursor::moveCursor(1, baseLine + currentOption.lineOffset);
        std::cout << currentOption.optionNumber << ") " << currentOption.optionText;
    }

    //resets the cursor's position to where it was before operation
    Cursor::resetCursor();
}

std::vector<int> Options::getOptionLineNumbers() {
    std::vector<int> lineNumbers;
    for(int i = 0; i < this->optionList.size(); i++) {
        lineNumbers.push_back(this->optionLineNumber + this->optionList[i].lineOffset);
    }
    return lineNumbers;
}

std::string Options::getOptionText(int index) {
    return this->optionList[index].optionText;
}

int Options::getOptionNumber(int index) {
    return this->optionList[index].optionNumber;
}