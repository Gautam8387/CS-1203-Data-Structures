// This code creates a Linked List from an Array and then print both Array and Linked List
// The input to the array and linked list are random values generated using rand() function

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

/* ========== Linked List ========== */
struct node {
	int val;
	struct node * next; // a pointer of type struct node which saves the address of next node
};

// 90% of times we are dealing with addresses of nodes
typedef struct node * NodeAddress; // creating a new data type NodeAddress and it is of struct node * type

/* ========== Generate Array ========== */
int * generateArray(int n){ 
	int * t; // declaring a new address
	t = malloc( n*sizeof(int) );
	if(t){ 
		for (int i = 0; i < n; i++){ t[i] = rand()%1000; } 
	}
	return t;
}

/* ========== Generate Linked List ========== */
// Given an array I have to create a linked list out of it
// Creating first element is a bit of specialty, because we need to stick the value inside head
// Function will return an address of type NodeAddress
NodeAddress linkedListFromArray(int * a, int n){
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;
	// special case for head
	if(n>0){
		head = malloc(sizeof(struct node));
		head->val = a[0];
		head->next = NULL;
		temp = head;
	}
	// Assuming first head already exist, we want to create a new house and and store its address in the previous house's next. Update the value of temp to new next and update value of val and set temp = NuLL
	// i starts from 1, coz head is already covered
	for(i=1; i<n; i++){
		temp->next = malloc(sizeof(struct node));
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}
	return head;
}

/* ========== Free Linked List ========== */

void freeLinkedList(NodeAddress head){
	// to destroy a linked list, you cannot destroy the element because you will loose the next element.
	// you have a thing that keeps moving ahead. Adter it has moved ahead, you delete the previous obeject.
	NodeAddress prev;
	while(head){
		prev = head;
		head = head->next;
		free(prev); // moving ahead one step, killing the last guy
	}
}

/* ========== Print Linked List ========== */
void printLinkedList(NodeAddress head){
	NodeAddress c;
	printf("Linked List = ");
	for (c = head; c; c=c->next){ //loop exits when c has the value NULL
		printf(c==head?"%d":", %d", c->val);
	}
	printf(".\n");

}

/* ========== Print Array ========== */

void printArray(int * a, int n){
	printf("Array = ");
	for (int i = 0; i < n; i++){
		printf(i?", %d":"%d", a[i]);
	}
	printf(".\n");
}


/* ========== main() ========== */

int main(int argc, char **argv){
	int * a;
	int n = 10;
	NodeAddress list;

	srand(time(NULL));
 
	a = generateArray(n);
	list = linkedListFromArray(a, n); // Create a linked list from this array
	// Return type is node address of type NodeAddress

	printArray(a, n); 

	printLinkedList(list);

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	freeLinkedList(list);
	return 0;
}


