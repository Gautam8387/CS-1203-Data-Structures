// Write a program for skip list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct skipList
{
    int data;
    struct skipList *next;
    struct skipList *down;
};
typedef struct skipList * nodeAddress;

nodeAddress generateLinkedList(int size){
    nodeAddress head = NULL;
    nodeAddress temp = NULL;
    nodeAddress current = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        temp = (nodeAddress)malloc(sizeof(struct skipList));
        temp->data = rand() % 100;
        temp->next = NULL;
        temp->down = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}


void printLinkedList(nodeAddress head){
    nodeAddress current = head;
    printf("Linked List = ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

// We will set a skip list with random jumps
void setSkipList(nodeAddress head){
    // We have a linked list, we will set a skip list with random jumps by setting the down pointer of the node
    nodeAddress current = head;
    nodeAddress temp = NULL;
    int i;
    while (current != NULL)
    {
        i = rand() % 10;
        temp = current;
        while (i > 0 && temp != NULL)
        {
            temp = temp->next;
            i--;
        }
        current->down = temp;
        current = current->next;
    }    
}

void printskipList(nodeAddress head){
    nodeAddress current = head;
    printf("\nSkip List = ");
    while (current != NULL && current->down != NULL)
    {
        printf("%d ", current->data);
        current = current->down;
    }
}

void freeLinkedList(nodeAddress head){
    nodeAddress current = head;
    nodeAddress temp = NULL;
    // first we free the down pointer
    while (current != NULL && current->down != NULL)
    {
        temp = current->down;
        free(temp);
        current = current->next;
    }
    // then we free the next pointer
    while (current != NULL && current->next != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the size of the Linked List: ");
    scanf("%d", &size);
    srand(time(NULL));
    nodeAddress head = generateLinkedList(size);
    printLinkedList(head);
    setSkipList(head);
    printskipList(head);
    freeLinkedList(head);
    return 0;
}
