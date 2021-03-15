#include "heap.h"

Heap::Heap (int n) {
    capacity = n;
    size = 0;
    H = new Element[n];
	/*for (int i = 0; i < n; i++) {
		H[i] = new ELEMENT {0};
	}*/
}

void Heap::PrintHeap () {
	//printf("sizeof=%d\n", (int)sizeof(this));
	printf("capacity=%d, size=%d\n", capacity, size);
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d\n", H[i].key);
		} else {
			printf("%d, ", H[i].key);
		}
	}
}

void Heap::WriteHeap () {
	ofstream outFile;
	outFile.open("HEAPoutput.txt");
	if (!outFile) {
		printf("Error: cannot open file for writing\n");
		return;
	}

	outFile << size << endl;
	int i = 0;
	while (i < size) {
		outFile << H[i].key << endl;
		i++;
	}

	outFile.close();
}

//int Heap::MinHeapify (Element* arr, int i) {
int Heap::MinHeapify (int i) {
	int smallest = -1;
	int left = (i * 2) + 1;
	int right = (i * 2) + 2;

	if (left < size && H[left].key < H[i].key) {
		smallest = left;
	} else {
		smallest = i;
	}

	if (right < size && H[right].key < H[smallest].key) {
		smallest = right;
	}

	if (smallest != i) {
		Element temp = H[i];
		H[i] = H[smallest];
		H[smallest] = temp;

		return 1 + MinHeapify(smallest);
	} else {
		return 1;
	}
}

int Heap::BuildMinHeap () {
	int count = 0;

	for (int i = (size / 2) - 1; i > -1; i--) {
		count += MinHeapify(i);
	}

	return count;
}

void Heap::ExtractMin(int flag) {
	int count = 
	printf("Deleted key: %d\n", H[0].key);
	H[0] = H[size - 1];
	size--;
	count = MinHeapify(0);

	if (flag == 1) {
		printf("Number of Heapify calls: %d\n", count);
	}
}

void Heap::DecreaseKey(int index, int value) {
	int i = index - 1;

	H[i].key = value;
	while ((i > 0) && (H[(i - 1) / 2].key > H[i].key)) {
		Element temp = H[i];
		H[i] = H[(i - 1) / 2];
		H[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
}

void Heap::Insert(int value) {
	size++;
	int i = size - 1;
	while ((i > 0) && (H[(i - 1) / 2].key > value)) {
		H[i] = H[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	H[i].key = value;
}