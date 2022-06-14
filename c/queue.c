//Queue Implementation
//
//Created By: Tommy Pett
//Date: 4/21/2022
//
//**Implement this file
//may change this file as needed

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct Queue Queue;
typedef struct Node Node;

//Create a new empty queue
//Inputs: None
//Outputs: A Pointer to a new empty queue
//Side Effects: None
//Note: Remember to set all the values correctly

struct Queue* newQueue(){
	Queue *Q = (Queue*) malloc( sizeof(Queue));
	Q->head = NULL;
	Q->tail = NULL;
	return Q;
}

//Determine if the Queue is Empty
//Inputs: Pointer to the Q
//Outputs: 1 if empty, 0 if contains values
//Side Effects: None
char isEmpty(struct Queue* Q){
	return Q->head == NULL; 
}

//Add a new value to the Queue
//Inputs: Value to Add and pointer to Queue
//Outputs: None
//Side Effects: Allocates memory for new value
// and modifies Queue
void enqueue(int v, struct Queue* Q){
	Node *n = (Node*) malloc( sizeof(Node));
	n->value = v;
	n->next = NULL; 
	if (Q->head == NULL) {
		Q->head = n;
		Q->tail = n;
	}
	else {
		Q->tail->next = n;
		Q->tail = n; 
	}
}

//Get value in front of queue
//Inputs: Pointer to Queue
//Outputs: First value in Queue or
//        -1 if empty
//Side Effects: None
int front(struct Queue* Q){
	if (Q->head == NULL){
		return -1; 
	}
	return Q->head->value;
}

// Get value in the back of the queue 
// Inputs: Pointer to queue
// Outputs: Last value in Queue or -1 if empty 
int tail(struct Queue* Q){
if (Q->tail == NULL){
      return -1;
   }
   return Q->tail->value;

}

//Remove the First Value from the Queue
//Inputs: Pointer to Queue
//Outputs: None
//Side Effects: Modifies Queue to remove first element
//	     Deletes first element from memory
//Reminder: Don't leak any memory!
void dequeue(struct Queue* Q){
	if (Q->head == NULL){
		return ;
	}
	Node *temp = (Node*) malloc( sizeof(Node) );
	temp = Q->head; 
	Q->head = Q->head->next;
	free(temp);
	if (Q->head == NULL){
		Q->tail = NULL; 
	}
}

//Print Queue to Help you Debug
//Inputs: Pointer to the Queue
//Outputs: None
//Side Effects: Prints the Queue to stdout
void printQueue(struct Queue* Q){
	if(Q->head==NULL){
		printf("Empty Queue\n");
		return;
	}
	struct Node* n = Q->head;
	printf("Queue Contents: [");
	while(n!=NULL){
		printf("%d",n->value);
		n=n->next;
		if(n!=NULL){
			printf(",");
		}
	}
	printf("]\n");
	return;
}

// needed to know how big the changed queue size is as iterated over
// Inputs: 
int getQueueSize(struct Queue* Q){
	int counter = 0;
	if (Q->head == NULL) {
		return counter; 
	}
	struct Node* n = Q->head; 
	while (n!= NULL){
		counter++; 
		n=n->next; 
	}
	return counter;
}
