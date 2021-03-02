#include <string>
#include <regex>
#include <iostream>
#include "util.h"

int nextCommand (int *n, int *f) {
    string input;
    getline(cin, input);

    if (regex_match(input, regex("[sSrRwWpP]"))) {
        return input.at(0);
    } else if (regex_match(input, regex("[cC] \\d+"))) {
        *n = stoi(input.substr(2));
        return input.at(0);
    } else {
        printf("Error: invalid input\n");
        return 0;
    }
}