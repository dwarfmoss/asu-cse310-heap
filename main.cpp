#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "util.h"
#include "heap.h"
// #include "element.h"
using namespace std;

int main() {
    char c;
    int n, f;
    int i;// int v;
    string line;
    ifstream inFile;
    ofstream outFile;
    HEAP* heap = NULL;

    while (1) {
        c = nextCommand(&n, &f);
        switch (c) {
            case 's':
            case 'S':   printf("COMMAND: %c\n", c); exit(0);

            case 'c':
            case 'C':   printf("COMMAND: %c %d\n", c, n);
                        heap = heapInit(n);
                        break;

            case 'r':
            case 'R':   printf("COMMAND: %c\n", c);
                        inFile.open("HEAPinput.txt");
                        if (!inFile) {
                            printf("Error: cannot open file for reading\n");
                            break;
                        }

                        if (!heap) {
                            printf("Error: heap overflow\n");
                            inFile.close();
                            break;
                        }
                        getline(inFile, line);
                        //printf("b1: %s\n", line.c_str());
                        if (stoi(line) > heap->capacity) {
                            printf("Error: heap overflow\n");
                            inFile.close();
                            break;
                        }

                        while (getline(inFile, line)) {
                            //printf("w1: %s\n", line.c_str());
                            heap->H[heap->size]->key = stoi(line);
                            heap->size++;
                        }
                        inFile.close();
                        break;

            case 'w':
            case 'W':   printf("COMMAND: %c\n", c);
                        if (heap) {
                            //File* oFile = fopen("HEAPoutput.txt", "w");
                            outFile.open("HEAPoutput.txt");
                            if (!outFile) {
                                printf("Error: cannot open file for writing\n");
                                break;
                            }
                            
                            outFile << heap->size << endl;
                            i = 0;
                            while (i < heap->size) {
                                outFile << heap->H[i]->key << endl;
                                i++;
                            }
                            
                            outFile.close();
                        } else {
                            printf("Error: heap is NULL\n");
                        }
                        break;

            case 'p':
            case 'P':   printf("COMMAND: %c\n", c);
                        if (heap) {
                            printHeap(heap);
                        } else {
                            printf("Error: heap is NULL\n");
                        }
                        break;

            default: break;
        }
    }
}