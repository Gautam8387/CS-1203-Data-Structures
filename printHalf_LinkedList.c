// WAP that prints the first half of a given Linked List without knowing how many elements in the array
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


void printLinkedListHalf(NodeAddress head){
    // We will try to implement the logic of finding the middle element of the linked list
    // We will use two pointers, one will move one step at a time and the other will move two steps at a time
    // When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle of the linked list
    // This algorithm is knows as Hare and Tortoise Pointer Algorithm
    NodeAddress slow_pointer = head;
    NodeAddress fast_pointer = head;
    while(fast_pointer != NULL && fast_pointer->next != NULL){
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
    }
    // Now slow is at the middle of the linked list
    // We will print the first half of the linked list
    NodeAddress temp = head;
    int i=0;
    printf("Half Linked List = ");
    while(temp != slow_pointer){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
        i++;
    }
}


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

/*==== Print Linked List ====*/
void printLinkedList(NodeAddress head, int n){
    NodeAddress temp = head;
    printf("Complete Linked List = ");
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
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    NodeAddress list, tail;         // declaring a new address for linked list
    srand(time(NULL));                  // seeding the random number generator
    list = generateLinkedList(n);       // calling the function to generate a linked list. The function returns the address of the head of the linked list
    printLinkedList(list, n);           // calling the function to print the linked list. The function prints the linked list

    printLinkedListHalf(list);           // print the Half list
    
    deleteLinkedList(list);                         // delete the linked list
    return 0;
}


