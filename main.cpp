#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"
// #include "element.h"
using namespace std;

int main() {
    char c;
    int i, f, v;
    HEAP* heap = NULL;

    while (1) {
        c = nextCommand(&i, &f, &v);
        switch (c) {
            case 's': // Stop program
            case 'S':   printf("COMMAND: %c\n", c); exit(0);
        
            case 'p': // Print Heap
            case 'P':   printf("COMMAND: %c\n", c);
                        if (heap) {
                            PrintHeap(heap);
                        } else {
                            printf("Error: heap is NULL\n");
                        }
                        break;
        
            case 'w': // Write Heap to file
            case 'W':   printf("COMMAND: %c\n", c);
                        if (heap) {
                            WriteHeap(heap);
                        } else {
                            printf("Error: heap is NULL\n");
                        }
                        
                        break;

            case 'c': // Create heap
            case 'C':   printf("COMMAND: %c %d\n", c, v);
                        heap = HeapInit(v);
                        break;
        
            case 'r': // Read heap data from file
            case 'R':   printf("COMMAND: %c %d\n", c, f);
                        ReadFile(heap, f);
                        break;
        
            case 'i': // Insert value into heap
            case 'I':   printf("COMMAND: %c %d\n", c, v);
                        
                        break;

            case 'd': // Delete min element from heap
            case 'D':   printf("COMMAND: %c %d\n", c, f);
                        
                        break;
        
            case 'k': // Decrease the value of the specified key to the specified value
            case 'K':   printf("COMMAND: %c %d %d\n", c, i, v);
                        
                        break;
        
            default: break;
        }
    }
}