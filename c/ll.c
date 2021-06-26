#include <stdbool.h>
#include <stdlib.h>

typedef struct sNode sNode;

struct sNode {
	int data;
	struct sNode* next; 
};
struct linkedList {
	struct sNode *head;
	size_t n;
};

linkedList* linkedListCreate()
{
	linkedList* a = (linkedList*) malloc (sizeof (linkedList));
	a->head = NULL;
	a->n = 0;
	return a;
}

size_t getSize(const linkedList* a )
{
	return a->n;
}

void append(linkedList* a, int n)
{
	sNode* new;
	new = (sNode*) malloc (sizeof(sNode));
	new->data = n;
	new->next = NULL;

	if (getSize(a) == 0)
	{
		a->head = new;
		a->n ++;
	}
	else
	{
		sNode* current = a->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
		a->n ++;
	}
}

bool remove(linkedList* a, int n)
{
	sNode* previous = NULL;
	sNode* current  = a->head;
	bool found = false;

	while (current!=NULL && !found)
        {
                if (current->data == n)
                {
                        found = true;
                }
		previous = current;
                current = current->next;
        }
	if (current == NULL){
		return false;
	}
	else if (previous == NULL){
		a->head = current->next;
		free(current);
		a->n --;
		return true;
	}
	else{
		previous->next = current->next;
		free(current);
		a->n --;
		return true;
}
