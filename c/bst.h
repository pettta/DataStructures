//Mark Boady
//Drexel 2022

//Struct and Operators for a BST

//Do not make any changes to this file.

#ifndef BST_LIBRARY_H
#define BST_LIBRARY_H

//Make our own Boolean Class for true/false results
enum bool{false=0, true=1};
typedef enum bool bool;

//A Data Structure to store a node
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

//A Data Structure for a BST
struct BST {
    Node* root;
};
typedef struct BST BST;

//Constructor
//Creates and returns a new BST
//The BST is empty (has no values)
BST* makeBST();

//Get Root
//This function returns a pointer to the root node
//It will be useful to implement later functions
//You may assume T is not null
Node* getRoot(BST* T);

//Primary Operations
//Insert value into tree into the tree given
//Call the helper function on the root of the tree
//Remember: A BST contains no duplicates
void insert(int value, BST* T);

//Find a value in the tree
//Start searching at the root of the tree
bool find(int value, BST* T);

//Delete a value
//Start searching for the value to delete
//at the root of the tree
//Use the **min** of the right subtree for replacements
void deleteFromTree(int value, BST* T);

//Find the min of the tree
//Start looks for the minimum at the root
int min(BST* T);

//Determine the height
int height(BST* T);

//Prints
//These will print directly to printf.
//Print Inorder
void inorder(BST* T);
//Prints Preorder
void preorder(BST* T);
//Prints Postorder
void postorder(BST* T);

//Helpers needed for recursion
//Do a print starting at the node given
//These are helpers to implement the above functions
void inorderWalker(Node* current);
void preorderWalker(Node* current);
void postorderWalker(Node* current);

//Insert Helper
//Insert value starting at current node
Node* insertValue(int v, Node* current);
//Find Helper
//Find value starting at current node
bool findValue(int value, Node* current);
//Min Helper
//Find the min starting at node current
//return -1 if the current==NULL
int findMin(Node* current);
//Height Helper
//Find Height of a Node
//return -1 if current==NULL
int nodeHeight(Node* current);
//Delete Helper
//Delete a value from the tree with search starting at current
Node* deleteValue(int v, Node* current);
//Give a pointer to a node, remove that node from the tree
//This should be used when deleteValue finds the node
Node* deleteNode(Node* current);

#endif
