// Tommy Pett
// Template for an open hash table


//This is the struct for a Node since we need a linked list for an open hash table
struct Node {
	char* value;
	struct Node* next; 
};

//This is the struct for a linked list since we need that for our open hash table 
struct LL {
	struct Node* head; 
	struct Node* tail; 
};


//LL creation
struct LL* newLL();

//LL Insertion
void insertLL(struct LL* l, char* string);

//LL search 
char searchLL(struct LL* l, char* string);


//This is the struct for the openHash Table 
struct OpenHash {
	int size;
	struct LL** A;
};

//Create a New Empty Hash
//Size of the underlying array is required 
struct OpenHash* newOpenHash(int size); 


//Hash A String
//See Pseudocode below for guidelines
int hash(char* string, int N);

//Is the item string a member of the hash table H 
//Return 1 for Yes and 0 for No
char member(char* string, struct OpenHash* H);

//Insert string into hash table H 
void insert(char* string, struct OpenHash* H);

//Hash stats 
//Print stats required for final project 
//See below for what stats this should print
void hashStats(struct OpenHash* H);
