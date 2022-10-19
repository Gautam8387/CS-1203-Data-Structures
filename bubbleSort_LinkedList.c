// Perform a bubble sort over a Linked List
// Sort the "value" in the linked list by swapping them


#include <stdio.h>
#include <stdlib.h>
#include <time.h> // need time.h to use srand (generate random numbers)

/* ========== Linked List ========== */
struct node {
	int val;
	struct node * next; // a pointer of type struct node which saves the address of next node
};

// 90% of times we are dealing with addresses of nodes
typedef struct node * NodeAddress; // creating a new data type NodeAddress and it is of struct node * type

/* ========== Bubble Sort ========== */
void bubbleSort(int * a, int n){
	int done, i, temp, swap; 

	for(done = 0; done<n; done++) {
		swap = 0;

		for (i = 0; i < n-1-done; i++) { 	
			if (a[i] > a[i+1]) {
				temp   = a[i];
				a[i]   = a[i+1];
				a[i+1] = temp;
				swap   = 1;
			}
		} // end of the i loop
		if(swap == 0)
			break;
	} // end of the done loop 
}

// we can swap two integer values in the nodes, or we can tear out the nodes and swap the nodes itself
// here we swap the integer values
NodeAddress bubbleSortLinkedList(NodeAddress head){
	// we are taking c and c next and we are swapping the value between them as when necessary
	// till up to when do you wanna go? First time the last element and then one before,...
	NodeAddress c, lastDone;
	int temp;
	//lastDone should contain the address of the node which was the last element to be put in place previously to current point in time 
	for (lastDone = NULL; lastDone != head; lastDone=c) { // update = whereever the inner loop finishes
		// I am comparing c and c->next and if lastDone is already in its correct place, then it'll never get switched. So i want c->next to not be equal lastDone. 
		for(c=head; c->next != lastDone; c=c->next ){
			if(c->val > c->next->val){
				temp 		 = c->val;
				c->val 		 = c->next->val;
				c->next->val = temp;
			} // end of c loop. The element has been bubbled up to position c 
		}
	}


	return head;
}

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

/* ========== Print Array ========== */

void printArray(int * a, int n){
	printf("Array = ");
	for (int i = 0; i < n; i++){
		printf(i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n){
	// Basic printing 
	for (int i = 0; i < n; i++){
		printf(" %d ", a[i]);
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
	bubbleSort(a, n); 
	printArray(a, n);

	printLinkedList(list);
	bubbleSortLinkedList(list);
	printLinkedList(list);
	

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	freeLinkedList(list);
	return 0;
}
