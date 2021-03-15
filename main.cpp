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
        case 'S':   exit(0);

        case 'p':
        case 'P':   if (heap) {
                        heap->PrintHeap();
                    } else {
                        printf("Error: cannot print\n");
                    }
                    break;

        case 'w':
        case 'W':   if (heap) {
                        heap->WriteHeap();
                    } else {
                        printf("Error: cannot write\n");
                    }

                    break;

        case 'c':
        case 'C':   heap = new Heap(v);
                    break;

        case 'r':
        case 'R':   ReadFile(heap, f);
                    break;

        case 'i':
        case 'I':   if (!heap || heap->size == heap->capacity) {
                        printf("Error: heap is NULL or full\n");
                    } else {
                        heap->Insert(v);
                    }
                    break;

        case 'd':
        case 'D':   if (!heap || heap->size == 0) {
                        printf("Error: heap is NULL or empty\n");
                    } else {
                        heap->ExtractMin(f);
                    }
                    break;

        case 'k':
        case 'K':   if (!heap || i < 0 || i > heap->size - 1 || v >= heap->H[i].key) {
                        printf("Error: invalid call to DecreaseKey\n");
                    } else {
                        heap->DecreaseKey(i, v);
                    }
                    break;

        default: break;
        }
    }
}