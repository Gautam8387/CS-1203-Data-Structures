/*

[10 points] Given the Head pointer of such a list, write a function to reverse the list.
    NodeAddress reverseLLWithNextK(NodeAddress head)
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

NodeAddress reverseLLWithNextK(NodeAddress head){
    // Your code goes here
    NodeAddress prev, curr, forward;
    curr = head; 
    prev = NULL; 
    forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        curr->nextk = NULL;             // setting next2 to NULL for each node and will set it to the next->next node in the next iteration
        prev = curr;
        curr = forward;
    }
    head = prev;
    // The linked list is reversed now
    // Now setting the pointer for k steps
    NodeAddress current = head;
    NodeAddress kth = head;
    while(current != NULL && current->next != NULL){
        // The value of k is already set for each node, we just need to reverse the pointers to this set value of k
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
    return head;
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
    current->k = rand() % 4 + 2;
    return head;
}

int main(int argc, char const *argv[])
{
    // Given an array 
    int a[10] = {34, 764, 35, 354, 69, 12, 34, 22, 67, 23};
    int n = 10;
    NodeAddress list, list_reverse;
    list = arrayToLLWithNextK(a, n);
    printLinkedList(list);

    list_reverse = reverseLLWithNextK(list);
    printLinkedList(list_reverse);

    return 0;
}



