#pragma once
#include <stdio.h>
#include <fstream>
using namespace std;

typedef struct TAG_ELEMENT {
    int key;
} ELEMENT;

typedef ELEMENT* ElementT;

typedef struct TAG_HEAP {
    int capacity; /* max size of the heap */
    int size; /* current size of the heap */
    ElementT *H; /* pointer to pointers to elements */
} HEAP;

HEAP* HeapInit (int);

void PrintHeap (HEAP*);
 
void WriteHeap (HEAP*); 