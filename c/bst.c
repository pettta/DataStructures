//Tommy Pett
//Drexel 5/12/2022

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

//Typedefinitions 
typedef enum bool bool;
typedef struct Node Node;
typedef struct BST BST;


//Constructor
//Creates and returns a new BST
//The BST is empty (has no values)
BST* makeBST() {
	BST* b = (BST*) malloc(sizeof(BST));
	b->root = NULL;
	return b; 
}

//Get Root
//This function returns a pointer to the root node
//It will be useful to implement later functions
//You may assume T is not null
Node* getRoot(BST* T) {
	return T->root; 
}

//Primary Operations
//Insert value into tree into the tree given
//Call the helper function on the root of the tree
//Remember: A BST contains no duplicates
void insert(int value, BST* T) {
	T->root = insertValue(value, T->root);
}

//Find a value in the tree
//Start searching at the root of the tree
bool find(int value, BST* T) {
	return findValue(value, T->root);
}

//Delete a value
//Start searching for the value to delete
//at the root of the tree
//Use the **min** of the right subtree for replacements
void deleteFromTree(int value, BST* T) {
	T->root = deleteValue(value, T->root);
}

//Find the min of the tree
//Start looks for the minimum at the root
int min(BST* T) {
	return findMin(T->root);
}

//Determine the height
int height(BST* T) {
	return nodeHeight(T->root);
}

//Prints
//These will print directly to printf.
//Print Inorder
void inorder(BST* T) {
	inorderWalker(T->root);
	printf("\n");
}

//Prints Preorder
void preorder(BST* T) {
	preorderWalker(T->root);
	printf("\n");
}

//Prints Postorder
void postorder(BST* T) {
	postorderWalker(T->root);
	printf("\n");
}

//Helpers needed for recursion
//Do a print starting at the node given
//These are helpers to implement the above functions
void inorderWalker(Node* current) {
	if (current == NULL) {
		return;
	}
	inorderWalker(current->left);
	printf("%d ", current->value);
	inorderWalker(current->right);
}
void preorderWalker(Node* current) {
	if (current == NULL) {
		return;
	}
	printf("%d ", current->value);
	preorderWalker(current->left);
	preorderWalker(current->right);
}
void postorderWalker(Node* current) {
	if (current == NULL) {
		return; 
	}
	postorderWalker(current->left);
	postorderWalker(current->right);
	printf("%d ", current->value);
}

//Insert Helper
//Insert value starting at current node
Node* insertValue(int v, Node* current) {
	if (current == NULL) {
		Node* a = (Node*) malloc(sizeof(Node));
		a->value = v;
		a->left = NULL;
		a->right = NULL;
		return a;
	}
	if (current->value == v) {
		return current;
	}
	if (current->value > v) {
		current->left = insertValue(v, current->left);
		return current;
	}
	current->right = insertValue(v, current->right);
	return current;
}

//Find Helper
//Find value starting at current node
bool findValue(int value, Node* current) {
	if (current == NULL) {
		return false; 
	}
	if (current->value == value) {
		return true; 
	}
	if (current->value > value) {
		return findValue(value, current->left);
	}
	return findValue(value, current->right); 
}

//Min Helper
//Find the min starting at node current
//return -1 if the current==NULL
int findMin(Node* current) {
	if (current == NULL) {
		return -1;
	}
	if (current->left == NULL) {
		return current->value; 
	}
	return findMin(current->left);
}

//Height Helper
//Find Height of a Node
//return -1 if current==NULL
int nodeHeight(Node* current) {
	if (current == NULL) {
		return -1;
	} 
	int leftHeight = nodeHeight(current->left);
	int rightHeight = nodeHeight(current->right);
	if (leftHeight > rightHeight) {
		return leftHeight + 1; 
	}
	return rightHeight + 1; 
}

//Delete Helper
//Delete a value from the tree with search starting at current
Node* deleteValue(int v, Node* current) {
	if (current == NULL) {
		return NULL;
	}
	if (current->value == v) {
		Node* a = (Node*) malloc(sizeof(Node));
		a = deleteNode(current);
		return a; 
	}
	if (current->value > v) {
		current->left = deleteValue(v, current->left);
		return current; 
	}
	current->right = deleteValue(v, current->right);
	return current; 
}

//Give a pointer to a node, remove that node from the tree
//This should be used when deleteValue finds the node
Node* deleteNode(Node* current) {
	if (current->left == NULL) {
		return current->right;
	}
	if (current->right == NULL) {
		return current->left;
	}
	int minVal = findMin(current->right);
	current->value = minVal;
	current->right = deleteValue(minVal, current->right);
	return current; 
}


