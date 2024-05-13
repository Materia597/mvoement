#ifndef OPTION_GENERATOR_H
#define OPTION_GENERATOR_H

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <map>
#include "cursorMovement.h"
#include <vector>

class option {
    public:
    std::string optionText;
    int optionNumber;
    int lineOffset;

    option(int optionNumber, std::string optionText, int lineOffset);
};

class Options {
public:
    std::vector<option> optionList;
    int optionLineNumber;
public:
    Options(int lineNumber);
    void addOption(option newOption);
    void displayOptions();
    std::vector<int> getOptionLineNumbers();
    std::string getOptionText(int index);
    int getOptionNumber(int index);
};

#endif