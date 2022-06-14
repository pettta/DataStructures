//Tommy Pett
//Open Hash Implementation
//Date: 4/29/22

#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node Node;
typedef struct LL LL;
typedef struct OpenHash OpenHash;

//Linked list methods 
//Helper methods that make our life with the hash table easier to implement 

//Create a new linked list 
struct LL* newLL(){
	LL *l = (LL*) malloc( sizeof(LL));
	l->head = NULL;
	l->tail = NULL; 
	return l; 
}

// Our insertion can act like a queue since we are just appending rather than
// worrying about where a value should be inserted on the linked list
void insertLL(struct LL* l, char* string) {
	Node *n  = (Node*) malloc(sizeof(Node));
	n->value = malloc(strlen(string) + 1);
	strcpy(n->value, string);
	if (l->head == NULL) {
		l->head = n;
		l->tail = n;
	}
	else {
		l->tail->next = n; 
		l->tail = n; 
	}
}

// Searches through the linked list LL, and if it finds a match it returns a bool value
// returns 0 if not found, 1 if found 
char searchLL(struct LL* l, char* string) {
	Node *current = l->head; 
	while (current != NULL) {
		if (strcmp(string, current->value) == 0) {
			return 1; 
		}
		current = current->next; 
	}
	return 0;
}

//Hash table methods

//Create a New Empty Hash
//Size of the underlying array is required 
struct OpenHash* newOpenHash(int size){
	OpenHash *H = (OpenHash * ) malloc( sizeof(OpenHash));
	LL** A = malloc(size *  sizeof(LL) );
	H->size = size;
	H->A = A;
	for (int i=0; i<size; i++){
		H->A[i] = newLL(); 		
	}
	return H; 
}


//Hash A String
//See Pseudocode below for guidelines
int hash(char* string, int N){
	int total = 0;
	int i = 0;
	char c;
	while (string[i]!= '\0') {
		c = string[i];
		total = total + (int) c;
		total = total * 101;
		total = total % N;
		i++;
	}
	return total;
}

//Is the item string a member of the hash table H 
//Return 1 for Yes and 0 for No
char member(char* string, struct OpenHash* H){
	int p = hash(string, H->size);
	LL *l = H->A[p];
	return searchLL(l, string);  
}

//Insert string into hash table H 
void insert(char* string, struct OpenHash* H){
	if (member(string, H)){ return; }
	int p = hash(string, H->size);
	LL *l = H->A[p];
	insertLL(l, string);  
}

//Hash stats 
//Print stats required for final project 
//See below for what stats this should print
void hashStats(struct OpenHash* H){
	int uniqueWords = 0;
	int rowWordsArr[H->size];
	double averageLength;
	for (int i = 0; i<H->size; i++){
		int rowWords = 0; 
		rowWordsArr[i] = 0;
		LL *l = H->A[i];
		if (l->head == NULL) {
			continue; 
		}
		Node *n = l->head;
		while (n != NULL) {
			uniqueWords++;
			rowWords++;
			n = n->next; 
		}
		rowWordsArr[i] = rowWords; 
	}
	printf("Hash Size: %d\n", H->size); 
	for (int i = 0; i<H->size; i++) {
		printf("Row %d contains %d values.\n", i, rowWordsArr[i]);
	}
	averageLength = uniqueWords / (double) (H->size);
   printf("Average Length: %.2f\n", averageLength);
}
