/*

[5 points] Now, we have four fields: val, next, k and nextk. Given a value for k, nextk points
k nodes ahead. (So the previous question merely had k=2, and a normal linked list has k=1.)
k is essentially a look-ahead. We want you to generate a random value of k for EACH node.
k only takes values between 2 and 5 (both included). You can use a C random library for this,
no issue. If at any point k overshoots the list i.e. k dictates that nextk points at an element
beyond the list, nextk should just be Null. Given an array with n elements, convert it into such
a linked list. All pointers should work correctly for full credit.

NodeAddress arrayToLLWithNextK(int *a , int n)
{
    // Your code goes here
    return head ;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NodeAddress{
    int val;
    struct NodeAddress *next;
    int k;
    struct NodeAddress *nextk;
};

typedef struct NodeAddress * NodeAddress;

void printLinkedList(NodeAddress head){
	NodeAddress c;
	printf("Linked List to check Value, Current, Next, Next2 addresses and K value = \n");
	for (c = head; c; c=c->next){ //loop exits when c has the value NULL
		printf(c==head?"%d":", %d", c->val);
        printf(" Current: %d, Next: %d, NextK: %d, K: %d\n",c,c->next,c->nextk,c->k);
	}
}

NodeAddress arrayToLLWithNextK(int *a, int n){
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct NodeAddress));
        head->val = a[0];
        head->next = NULL;
        head->nextk = NULL;
        temp = head;
    }
    // general case
    for(int i=1; i<n; i++){
        temp->next = malloc(sizeof(struct NodeAddress));
        temp = temp->next;
        temp->val = a[i];
        temp->next = NULL;
        temp->nextk = NULL;
    }

    // Now setting the pointer for k steps
    NodeAddress current = head;
    NodeAddress kth = head;
    while(current != NULL && current->next != NULL){
        // setting the value of k
        current->k = rand() % 4 + 2;        // random number between 2 and 5 (both included) : rand() % (max_number + 1 - minimum_number) + minimum_numbers
        // setting the pointer for k steps
        // We will keep updating nextK to the next node until we reach the kth node
        for(int i=0; i<current->k; i++){
            if(kth->next != NULL){
                kth = kth->next;
            }
            else{
                kth = NULL;
                break;
            }
        }
        current->nextk = kth;
        current = current->next;
        kth = current;
    }
    // seeting the k value for last node    
    current->k = rand() % 4 + 2;
    return head;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL)); // seeding the random value generator
    int a[10] = {34, 764, 35, 354, 69, 12, 34, 22, 67, 23};
    int n = 10;
    NodeAddress list;
    list = arrayToLLWithNextK(a, n);
    printLinkedList(list);
    return 0;
}


