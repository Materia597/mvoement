#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <stdio.h>
#include "optionGenerator.h"
#include "cursorMovement.h"

class OptionInformation {
private:
    Options currentOption;
    std::vector<int> lineNumbers;
    int currentLineIndex;
public:
    OptionInformation(Options currentOption, std::vector<int>, int currentLineIndex);

    std::string getOptionText();
    int getOptionNumber();

    option selectOption();

    static OptionInformation OptionInformationBuilder(Options option);

    bool optionSelect(char key);
};

