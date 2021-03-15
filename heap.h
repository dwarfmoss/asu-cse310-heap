#pragma once
#include <stdio.h>
#include <fstream>
#include "element.h"
using namespace std;

struct Heap {
    int capacity;
    int size;
    Element* H;

    //Constructor
    Heap (int);

    void PrintHeap ();
    void WriteHeap ();

    int MinHeapify (int);
    int BuildMinHeap ();
    void ExtractMin(int);
    void DecreaseKey(int, int);
    void Insert(int);
};