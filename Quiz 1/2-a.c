/*

[5 points] Consider a linked list with three fields: val, next, and next2. Here, next2 points
two nodes ahead, i.e., next next. Given an array with n elements, convert it into such a linked
list. All pointers should work correctly for full credit.
NodeAddress arrayToLLWithNext2(int *a, int n)
{
    // Your code goes here
    return head;
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

// We will follow a similar kind of logic as we did while printing the half linked list. A kind of Hare and Tortoise Pointer Algorithm
NodeAddress arrayToLLWithNext2(int *a, int n){
    // Your code goes here
    
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
}

int main(int argc, char const *argv[])
{
    // Given an array 
    int a[10] = {34, 764, 35, 354, 69, 12, 34, 22, 67, 23};
    int n = 10;
    NodeAddress list;
    list = arrayToLLWithNext2(a, n);
    printLinkedList(list, n);
    return 0;
}
