#include "util.h"

int nextCommand (int* i, int* f, int* v) {
    string input;
    smatch sm;
    getline(cin, input);

    if (regex_match(input, sm, regex("([sSwWpP])"))) {
        return input.at(0);
    } else if (regex_match(input, sm, regex("([cCiI]) (\\d+)"))) {
        *v = stoi(sm.str(2).c_str());
        return input.at(0);
    } else if (regex_match(input, sm, regex("([rRdD]) (\\d+)"))) {
        *f = stoi(sm.str(2).c_str());
        return input.at(0);
    } else if (regex_match(input, sm, regex("([kK]) (\\d+) (\\d+)"))) {
        *i = stoi(sm.str(2).c_str());
        *v = stoi(sm.str(3).c_str());
        return input.at(0);
    } else {
        printf("Error: invalid input\n");
        return 0;
    }
}

void ReadFile(HEAP *heap, int f) {
    ifstream inFile;
    string line;
    int count = 0;

    inFile.open("HEAPinput.txt");
    if (!inFile) {
        printf("Error: cannot open file for reading\n");
        return;
    }

    if (!heap) {
        printf("Error: heap overflow\n");
        inFile.close();
        return;
    }
    getline(inFile, line);
    //printf("b1: %s\n", line.c_str());
    if (stoi(line) > heap->capacity) {
        printf("Error: heap overflow\n");
        inFile.close();
        return;
    }

    while (getline(inFile, line)) {
        //printf("w1: %s\n", line.c_str());
        heap->H[heap->size]->key = stoi(line);
        heap->size++;
    }
    
    if (f == 1) {
        printf("Number of Heapify calls: %d", count);
    }
    
    inFile.close();
}