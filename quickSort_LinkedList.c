// WAP to perform quick sort on a linked list of integers

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

/*==== Parition ====*/
// We will follow the same logic as we did in the array but imply that to linked list
// We will take the last element as pivot and place it at its correct position in sorted array and place all smaller elements to left of pivot and all greater elements to right of pivot
NodeAddress parition(NodeAddress start, NodeAddress end){
    // start is the first element of the linked list part being sorted
    // end is the last element of the linked list part being sorted
    // We will take the first element as pivot and place it at its correct position in sorted array and place all smaller elements to left of pivot and all greater elements to right of pivot
    int pivot = start->val;
    NodeAddress wall = start; // wall is the first element of the linked list
    NodeAddress scout = start->next; // j is the next element to wall of the linked list
    while(scout != end->next){
        if(scout->val < pivot){
            wall = wall->next;
            int swap_temp = wall->val;
            wall->val = scout->val;
            scout->val = swap_temp;
        }
        scout = scout->next;
    }
    int swap_temp = wall->val;
    wall->val = start->val;
    start->val = swap_temp;
    
    return wall;
}

/*==== Quick Sort ====*/
int quickSortLinkedList(NodeAddress head, NodeAddress tail){
    // We will follow the similar recursive approach as we did in the array
    if (head == tail){
        return 0;
    }    
    NodeAddress pivot = parition(head, tail);
    // Quick Sort the right half
    if (pivot != NULL && pivot->next != NULL){
        quickSortLinkedList(pivot->next, tail);
    }
    // Quick Sort the left half
    if (pivot != NULL && head != NULL){
        quickSortLinkedList(head, pivot);
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

/*=== Get Tail ====*/
NodeAddress getTail(NodeAddress head){
    NodeAddress temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
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
    NodeAddress list, tail;         // declaring a new address for linked list
    srand(time(NULL));                  // seeding the random number generator
    list = generateLinkedList(n);       // calling the function to generate a linked list. The function returns the address of the head of the linked list
    tail = getTail(list);
    printLinkedList(list, n);           // calling the function to print the linked list. The function prints the linked list

    quickSortLinkedList(list, tail);                // calling the function to sort the linked list using selection sort. 

    printLinkedList(list, n);           // print the sorted list
    deleteLinkedList(list);                         // delete the linked list
    return 0;
}


