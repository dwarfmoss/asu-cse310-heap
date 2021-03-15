#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "util.h"
#include "heap.h"
using namespace std;

int main() {
    char c;
    int i, f, v;
    Heap* heap = NULL;

    while (1) {
        c = nextCommand(&i, &f, &v);
        switch (c) {
        case 's':
        case 'S':   printf("COMMAND: %c\n", c); exit(0);

        case 'p':
        case 'P':   printf("COMMAND: %c\n", c);
                    if (heap) {
                        heap->PrintHeap();
                    } else {
                        printf("Error: cannot print\n");
                    }
                    break;

        case 'w':
        case 'W':   printf("COMMAND: %c\n", c);
                    if (heap) {
                        heap->WriteHeap();
                    } else {
                        printf("Error: cannot write\n");
                    }

                    break;

        case 'c':
        case 'C':   printf("COMMAND: %c %d\n", c, v);
                    heap = new Heap(v);
                    break;

        case 'r':
        case 'R':   printf("COMMAND: %c %d\n", c, f);
                    ReadFile(heap, f);
                    break;

        case 'i':
        case 'I':   printf("COMMAND: %c %d\n", c, v);
                    if (!heap || heap->size == heap->capacity) {
                        printf("Error: heap is NULL or full\n");
                    } else {
                        heap->Insert(v);
                    }
                    break;

        case 'd':
        case 'D':   printf("COMMAND: %c %d\n", c, f);
                    if (!heap || heap->size == 0) {
                        printf("Error: heap is NULL or empty\n");
                    } else {
                        heap->ExtractMin(f);
                    }
                    break;

        case 'k':
        case 'K':   printf("COMMAND: %c %d %d\n", c, i, v);
                    if (!heap || i < 0 || i > heap->size - 1 || v >= heap->H[i].key) {
                        printf("Error: invalid call to DecreaseKey\n");
                    } else {
                        heap->DecreaseKey(i, v);
                    }
                    break;

        default: break;
        }
    }
}