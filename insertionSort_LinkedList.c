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

/*==== Insert New Element ====*/
void InsertNewElement(NodeAddress head, int x)
{
    // Create a new node
    NodeAddress newnode = malloc(sizeof(struct Node));
    newnode->val = x;
    // Now set the address of the new node to the head so it gets linked to the Linked List
    newnode->next = head;
    // Now set the head to the new node
    head = newnode;
}

NodeAddress insertionSort_LinkedList(int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    int input;
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct Node));
        printf("Enter the value 1: ");
        scanf("%d", &input);
        head->val = input;                  // assigning a random value to the head->val
        head->next = NULL;                  // assigning NULL to the head->next
        temp = head;
    }
    // general case
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next; 
        printf("Enter the value %d: ", i+1);
        scanf("%d", &input);
        temp->val = input;            // assigning a random value to the temp->val
        temp->next = NULL;                  // assigning NULL to the temp->next
// We follow the same procedure as we did in the selection sort for arrays
// For the insertion sort we have to insert the element at the correct position
// We have to compare the element with the previous element and if it is smaller than the previous element then we have to insert it at the correct position
// We have to do this for all the elements in the list
        for(NodeAddress temp2 = head; temp2 != temp; temp2=temp2->next)
            {
                if(temp2->val >= temp2->next->val){
                    int swap_temp = temp2->val;
                    temp2->val = temp2->next->val;
                    temp2->next->val = swap_temp;
                }
            }
    }
    return head;                            // returning the address of the head of Linked List
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
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    NodeAddress list, list_rev;         // declaring a new address for linked list
    srand(time(NULL));                  // seeding the random number generator
    list = insertionSort_LinkedList(n);       // calling the function to generate a linked list. The function returns the address of the head of the linked list
    printLinkedList(list, n);           // calling the function to print the linked list. The function prints the linked list
    deleteLinkedList(list);                         // delete the linked list
    return 0;
}


