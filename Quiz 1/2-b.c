/*

[10 points] Given the head pointer of such a list, write a function to reverse the list.
NodeAddress reverseLLWithNext2(NodeAddress head)
{
    // Your code goes here
    return head ;
}

*/

#include <stdio.h>
#include <stdlib.h>

// creating linked list with 3 fields: val, next, and next2
struct NodeAddress{
    int val;
    struct NodeAddress *next;
    struct NodeAddress *next2;
};
// Since we will be dealing with the address of the nodes, we will use pointer to the structure.
typedef struct NodeAddress * NodeAddress;


////////////////////////////////
/*==== Reverse Linked List ====*/
// Reversing the linked list follows a simple procedure.
// 1. Take 3 pointers, prev, curr and forward.
// 2. Initialize prev as NULL, curr as head and forward as NULL.
// 3. Traverse the linked list. change pointers of current node to point to previous node.
// Using the same code from my github: https://www.github.com/Gautam8387

NodeAddress reverseLLWithNext2(NodeAddress head){
    // Your code goes here
    NodeAddress prev, curr, forward;
    curr = head; 
    prev = NULL; 
    forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        curr->next2 = NULL;             // setting next2 to NULL for each node and will set it to the next->next node in the next iteration
        prev = curr;
        curr = forward;
    }
    // The linked list is reversed now. prev is the new head of the reversed linked list. We need to change the next2 pointers.
    NodeAddress slow_pointer = prev;
    NodeAddress fast_pointer = slow_pointer->next;
    // The fast pointer will move one steps ahead of the slow pointer
    while(fast_pointer != NULL && fast_pointer->next != NULL){
        slow_pointer->next2 = fast_pointer->next;
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next;
    }

    head = prev;
    return head;
}

// We will follow a similar kind of logic as we did while printing the half linked list. A kind of Hare and Tortoise Pointer Algorithm
NodeAddress arrayToLLWithNext2(int *a, int n){
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct NodeAddress));
        head->val = a[0];
        head->next = NULL;
        head->next2 = NULL;
        temp = head;
    }
    // general case
    for(int i=1; i<n; i++){
        temp->next = malloc(sizeof(struct NodeAddress));
        temp = temp->next;
        temp->val = a[i];
        temp->next = NULL;
        temp->next2 = NULL;
    }

    // Now we will assign the next2 pointer to the correct address
    NodeAddress slow_pointer = head;
    NodeAddress fast_pointer = slow_pointer->next;
    // The fast pointer will move one steps ahead of the slow pointer
    while(fast_pointer != NULL && fast_pointer->next != NULL){
        slow_pointer->next2 = fast_pointer->next;
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next;
    }
    return head;
}

void printLinkedList(NodeAddress head, int n){
    NodeAddress temp = head;
    printf("Linked List to check Value, Current, Next and Next2 addresses = \n");
    for(int i=0; i<n; i++){
        // print the value and address 
        printf("Value: %d, Current: %d, Next: %d, Next2: %d\n", temp->val, temp, temp->next, temp->next2);
        temp = temp->next;
    }
    printf(".\n");
}

int main(int argc, char const *argv[])
{
    // Given an array 
    int a[10] = {34, 764, 35, 354, 69, 12, 34, 22, 67, 23};
    int n = 10;
    NodeAddress list, list_reverse;
    list = arrayToLLWithNext2(a, n);

    printLinkedList(list, n);

    list_reverse = reverseLLWithNext2(list);
    printf("Reversed ");
    printLinkedList(list_reverse, n);
    
    return 0;
}
