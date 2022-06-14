//Tommy Pett
// May 19th 2022
//Heap Sort Library
//CS 260

typedef struct Heap Heap;
int pickSmallerChild(struct Heap* H, int left, int right);
void expand(struct Heap* H);
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

//Heapsort Sort
//Sort using a heap data structure
void heapSort(int* Array, int size) {
	Heap* H = makenull(size);
	for (int i= 0; i < size; i++) {
		insert(Array[i], H);
	}
	int j = 0;
	while (!empty(H)) {
		Array[j] = min(H);
		deletemin(H);
		j++;
	}
	free(H);
}


//Make a new Heap
struct Heap* makenull(int capacity) {
	Heap* h = (Heap*) malloc(sizeof(Heap));
	h->data = malloc(capacity * sizeof(int));
	h->currentSize = 0;
	h->maxSize = capacity;
	return h;
}

//Is the heap empty?
char empty(struct Heap* H) {
	if (H->currentSize == 0) {
		return 1;
	}
	return 0;
}

//What is the min?
int min(struct Heap* H) {
	if (empty(H) == 1) {
		return 0;
	}
	return H->data[0];
}

//Delete the min
void deletemin(struct Heap* H) {
	if (empty(H) == 1) {
		return;
	}
	swap(H, 0, H->currentSize - 1);
	H->currentSize = H->currentSize - 1;
	downheap(H, 0);
}

//Downheap a value at index i
void downheap(struct Heap* H, int i) {
	int leftIndex = leftChild(i);
	int rightIndex = rightChild(i);
	if (leftIndex >= H->currentSize) {
		return; 
	}
	int minIndex = pickSmallerChild(H, leftIndex, rightIndex); // TODO implement pick smaller child 
	if (H->data[i] > H->data[minIndex]) {
		swap(H, i, minIndex);
		downheap(H, minIndex);
	}
	return; 
}

//Insert a new value
void insert(int x, struct Heap* H) {
	if (H->currentSize == H->maxSize) {
		expand(H);  
	}
	H->data[H->currentSize] = x;
	H->currentSize++;
	upheap(H, H->currentSize - 1);
	return;
}

//Upheap a value at index i
void upheap(struct Heap* H, int i) {
	int p = parent(i);
	if (p < 0) {
		return;
	}
	int pVal = H->data[p];
	if (pVal <= H->data[i]) {
		return; 
	}
	swap(H, i, p);
	upheap(H, p);
	return;
}

//Get Index of Parent
int parent(int n) {
	if (n == 0) {
		return -1;
	}
	return ((n - 1) / 2);
}

//Get index of Left Child
int leftChild(int n) {
	return ((2 * n) + 1);
}

//Get index of Right Child
int rightChild(int n) {
	return ((2 * n) + 2);
}

//Swap i and j in heap
void swap(struct Heap* H, int i, int j) {
	int temp = H->data[i];
	H->data[i] = H->data[j];
	H->data[j] = temp;
	return; 
}

//Just to help debug
//You will want to use this if anything
//goes wrong in your code
void printHeap(struct Heap* H) {
	printf("Heap Current Size: %d\n", H->currentSize);
	printf("Heap Max Size: %d\n", H->maxSize);
	printf("Contents:\n");
	for (int i = 0; i < H->currentSize; i++) {
		printf("%d ", H->data[i]);
	}
	printf("\n");
}


int pickSmallerChild(struct Heap* H, int left, int right) {
	int minIndex;
	if (right >= H->currentSize) {
		minIndex = left;
	}
	else {
		if (H->data[left] < H->data[right]) {
			minIndex = left;
		}
		else {
			minIndex = right;
		}
	}
	return minIndex;
}

void expand(struct Heap* H) {
	int newSize = 2 * H->currentSize;
	int* newData = malloc(newSize * sizeof(int));
	for (int i = 0; i < H->currentSize; i++) {
		newData[i] = H->data[i];
	}
	H->data = newData;
	H->maxSize = newSize;
	return;
}
