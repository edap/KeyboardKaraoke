#pragma once
#include "ofMain.h"

class Parser{
public:
    static string stringWithValidChars(string str, string reg);
    static bool isValidKey(int key, string reg);
    static bool isStringInRegex(string str, string reg);
};