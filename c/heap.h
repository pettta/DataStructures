//Mark Boady
//Heap Sort Library
//CS 260

//You may not change this file

#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>

//Heapsort Sort
//Sort using a heap data structure
void heapSort(int* Array, int size);

//The Heap data structure
struct Heap{
	int* data;
	int maxSize;
	int currentSize;
};

//Make a new Heap
struct Heap* makenull(int capacity);

//Is the heap empty?
char empty(struct Heap* H);

//What is the min?
int min(struct Heap* H);

//Delete the min
void deletemin(struct Heap* H);

//Downheap a value at index i
void downheap(struct Heap* H, int i);

//Insert a new value
void insert(int x, struct Heap* H);

//Upheap a value at index i
void upheap(struct Heap* H,int i);

//Get Index of Parent
int parent(int n);

//Get index of Left Child
int leftChild(int n);

//Get index of Right Child
int rightChild(int n);

//Swap i and j in heap
void swap(struct Heap* H, int i, int j);

//Just to help debug
//You will want to use this if anything
//goes wrong in your code
void printHeap(struct Heap* H);


#endif
