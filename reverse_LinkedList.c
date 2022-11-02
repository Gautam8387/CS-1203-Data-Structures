// WAP to Reverse a Linked List 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*==== Linked Liste Structure ====*/
// defining a linked list structure
struct Node{
    int val;
    struct Node * next;
};

typedef struct Node * NodeAddress;  // creating a new data type NodeAddress and it is of struct node * type

/*==== Generate Linked List ====*/
NodeAddress generateLinkedList(int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct Node));
        head->val = rand()%1000;            // assigning a random value to the head->val
        head->next = NULL;                  // assigning NULL to the head->next
        temp = head;
    }
    // general case
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next;
        temp->val = rand()%1000;            // assigning a random value to the temp->val
        temp->next = NULL;                  // assigning NULL to the temp->next
    }
    return head;                            // returning the address of the head of Linked List
}

/*==== Reverse Linked List ====*/
// Reversing the linked list follows a simple procedure.
// 1. Take 3 pointers, prev, curr and forward.
// 2. Initialize prev as NULL, curr as head and forward as NULL.
// 3. Traverse the linked list. In loop, do following.
//      Before changing next of current,
//      store next node
//      forward = curr->next
//      Now change next of current
//      This is where actual reversing happens
//      curr->next = prev
//      Move prev and curr one step forward
//      prev = curr
//      curr = forward

// At the end, forward and curr both become NULL and the prev becomes the head of the reversed linked list.
// This is the reason why we return prev as the head of the reversed linked list.
// All the original next values of node are changed to prev values.

NodeAddress reverseLinkedList(NodeAddress head){
    NodeAddress prev, curr, forward;
    curr = head; 
    prev = NULL; 
    forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}

/*==== Print Linked List ====*/
void printLinkedList(NodeAddress head, int n){
    NodeAddress temp = head;
    printf("Linked List = ");
    for(int i=0; i<n; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
    printf(".\n");
}
/*==== Delete Linked List ====*/
void deleteLinkedList(NodeAddress head){
    NodeAddress prev;
	while(head){                // while head is not NULL. When the head is NULL it will be the last node
		prev = head;
		head = head->next;
		free(prev); // moving ahead one step, killing the last guy
	}
}


/*==== main ====*/
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    NodeAddress list, list_rev;         // declaring a new address for linked list
    srand(time(NULL));                  // seeding the random number generator
    list = generateLinkedList(n);       // calling the function to generate a linked list. The function returns the address of the head of the linked list
    printLinkedList(list, n);           // calling the function to print the linked list. The function prints the linked list
    list_rev = reverseLinkedList(list);          // calling the function to reverse the linked list. The function returns the address of the head of the reversed linked list
    printLinkedList(list_rev, n);                   // print the reversed linked list
    deleteLinkedList(list);                         // delete the linked list
    deleteLinkedList(list_rev);                     // delete the reversed linked list
    return 0;
}
