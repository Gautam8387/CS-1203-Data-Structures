// Given head pointer of a linked list, and an integer k (1<=k<=n), reverse the first k nodes of the linked list. If k>n, reverse the whole linked list.
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


/*==== Chunk Reverse ====*/
// We use the same logic as we did in the reversing a linked list
// We will use three pointers, one will point to the current node, one will point to the previous node and one will point to the next node
// We will reverse the linked list by changing the next pointer of the current node to the previous node
// We will do this for k nodes, if k=n, we will reverse the whole linked list
// After k nodes, we will return the head of the reversed linked list
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

NodeAddress chunkReverse(NodeAddress head, int k){
    NodeAddress curr = head;            // curr points to the current node
    NodeAddress prev = NULL;            // prev points to the previous node
    NodeAddress forward = NULL;         // forward points to the next node
    if(k==0){                           // Return head if zero chunks are selected 
        return head;
    }
    for(int i=0; i<k && curr!=NULL; i++){    // Traverse the linked list for k nodes, if k>n, traverse till the end of the linked list
        forward = curr->next;                // Store the next node in forward
        curr->next = prev;                   // Change the next pointer of the current node to the previous node
        prev = curr;                         // Set the previous node address to the current node address
        curr = forward;                      // Set the current node address to the forward node address
    }
    head->next = curr;                       // Set the next pointer of the head to the current node address
    head = prev;                             // Set the head to the previous node address
    return head;
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
    int n,k;
    printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    NodeAddress list, chunk;         // declaring a new address for linked list
    srand(time(NULL));                  // seeding the random number generator
    list = generateLinkedList(n);       // calling the function to generate a linked list. The function returns the address of the head of the linked list
    printLinkedList(list, n);           // calling the function to print the linked list. The function prints the linked list

    printf("Enter the value of k: ");
    scanf("%d", &k);

    chunk = chunkReverse(list, k);
    
    printLinkedList(chunk, n);           // calling the function to print the linked list. The function prints the linked list

    deleteLinkedList(list);                         // delete the linked list
    deleteLinkedList(chunk);                         // delete the linked list
    return 0;
}

