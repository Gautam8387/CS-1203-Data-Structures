// WAP to perform selection sort on a linked list of integers

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

/*==== Selection Sort ====*/
// Selection sort is a here will sort a linked list by repeatedly finding the maximum element from unsorted part and putting it at the ending. The algorithm maintains two subarrays in a given array.


void selectionSortLinkedList(NodeAddress head){
    NodeAddress temp, max, prev, curr;     // declaring the pointers
    temp = head;                                    // assigning the head to temp
    while(temp->next != NULL){                      // Condition for List End
        max = temp;                               // max holds the address of the maximum value
        prev = temp;                                
        curr = temp->next;                         // curr is the next node of temp
        // We Move the Value to End of the List    
        while(curr != NULL){
            if(curr->val < max->val){               // if the value of the current node is less than the value of the min node; The previous value is greater than te new value
                max = curr;                         // then we assign the current node to the min node and it will point to the minium element address 
            }
            curr = curr->next;                      // update current to check next
        }

        // We Swap the Value with the End of the List
        int swap_temp = temp->val;
        temp->val = max->val;
        max->val = swap_temp;
        
        // update temp to next node and the smallest value is at the head node
        temp = temp->next;                          
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
    NodeAddress list;         // declaring a new address for linked list
    srand(time(NULL));                  // seeding the random number generator
    list = generateLinkedList(n);       // calling the function to generate a linked list. The function returns the address of the head of the linked list
    printLinkedList(list, n);           // calling the function to print the linked list. The function prints the linked list
    selectionSortLinkedList(list);                // calling the function to sort the linked list using selection sort. 
    printLinkedList(list, n);           // print the sorted list
    deleteLinkedList(list);                         // delete the linked list
    return 0;
}


