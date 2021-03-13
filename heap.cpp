#include "heap.h"

HEAP* HeapInit (int n) {
    // Dynamically allocate heap and element array
    ElementT* elArr = new ElementT[n];
    for (int i = 0; i < n; i++) {
        ElementT temp = new ELEMENT {0};
        elArr[i] = temp;
    }
	// for (int i = 0; i < n; i++) {
	// 	if (i == n - 1) {
	// 		printf("%d\n", elArr[i]->key);
	// 	} else {
	// 		printf("%d, ", elArr[i]->key);
	// 	}
	// }
    return new HEAP {n, 0, elArr};
}

void PrintHeap (HEAP* heap) {
	//printf("sizeof=%d\n", (int)sizeof(heap));
	printf("capacity=%d, size=%d\n", heap->capacity, heap->size);
	for (int i = 0; i < heap->size; i++) {
	    if (i == heap->size - 1) {
	        printf("%d\n", heap->H[i]->key);
	    } else {
	        printf("%d, ", heap->H[i]->key);
	    }
	}
}

void WriteHeap (HEAP* heap) {
    ofstream outFile;
	//File* oFile = fopen("HEAPoutput.txt", "w");
	outFile.open("HEAPoutput.txt");
	if (!outFile) {
		printf("Error: cannot open file for writing\n");
		return;
	}
	
	outFile << heap->size << endl;
	int i = 0;
	while (i < heap->size) {
		outFile << heap->H[i]->key << endl;
		i++;
	}
	
	outFile.close();
}