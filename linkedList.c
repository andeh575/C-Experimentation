/* 	Author:		Andrew Graham
/	Date: 		19 August 2015
/	Purpose:	A simple example of a linked-list data structure
/
	STACK		|   HEAP
/	-------- 	|   ---------------     ---------------     
/	| HEAD | -- |-> | DATA | NEXT | --> | Data | NEXT | --> NULL 
/	--------	|   ---------------     ---------------     
/				|
*/
#include <stdio.h>
#include <stdlib.h> // Needed for malloc() and free()

// Type for nodes which make up the body of the list. Allocated in the heap.
struct node {
	int val;
	struct node* next;	
};

struct node* buildSample();
int length(struct node* head);
void push(struct node** headref, int val); 

int main(void) {
	
	
	// Let's build a sample list to test it's length
	printf("Building a sample list with: buildSample()\n\n");
	struct node* myList = buildSample();
	
	int len = length(myList);
	printf("The sample list has a length of: %d\n", len);
	
	printf("Adding two new nodes to the list...\n\n");
	push(&myList, 5);
	push(&myList, 7);
	
	len = length(myList);
	printf("The sample list has a length of: %d\n", len);

	return 0;
}

// Creation of three sample nodes to put into the linked list
struct node* buildSample() {
	struct node* head = NULL; 
	struct node* two = NULL; 
	struct node* three = NULL;
	
	// Allocate 3 nodes in the heap
	head = malloc(sizeof(struct node));
	two = malloc(sizeof(struct node));
	three = malloc(sizeof(struct node));
	
	// Ensure proper allocation
	if(head == NULL || two == NULL || three == NULL)
		printf("Error allocating memory in the heap.\n");
	
	// Assigning values to each node
	head->val = 1;
	head->next = two;
	
	two->val = 2;
	two->next = three;
	
	three->val = 3;
	three->next = NULL;
	
	return head;
}

/*	Given a list head pointer, computer and return number of nodes in list.
/	
/	Notes:
/	- 	List is being passed by the head pointer. This copies the pointer into the local 'head' 
/		pointer of length(). The effect is that both the caller and length() both have pointers to 
/		the same list structure - but the list itself is not copied!
*/
int length(struct node* head) {
	// 	Starts at the head of the linked list - automatically deallocated since it is just local,
	//	but objects on the heap remain.
	struct node* current = head; 
	int count = 0;
	
	// Tests for the end of list - catches the empty list scenario too
	while(current != NULL) {
		++count;
		current = current->next;	// Moves to next item of the list - NULL if current was last
	}
	
	return count;
}

/* 	Given a list and a data value this function creates a new link with the given data and 
/ 	pushes it onto the front of the list.
/
/	Notes:
/	-	List not passed in by head pointer - list is passed in as a 'reference' pointer to the
/		the head pointer. This allows the modification of the caller's memory. 
/	-	"If you want to modify caller memory then you have to pass a pointer to the memory
/		 not just a copy of the memory." 
*/
void push(struct node** headRef, int data) {
	// Allocate memory and store data into the new node
	struct node* newNode = malloc(sizeof(struct node));
	
	newNode->val = data;
	newNode->next = *headRef; // '*' Dereferences headRef back to the real head pointer 
	*headRef = newNode;			
}

