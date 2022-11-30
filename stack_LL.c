// Write a program to create a stack using Linked List
// A stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
// Mainly the following three basic operations are performed in the stack:
// Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
// Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
// Peek or Top: Returns top element of stack.

#include<stdio.h>
#include<stdlib.h>

struct stack_LL
{
    int data;
    struct stack_LL *next;
};
typedef struct stack_LL * nodeAddress;

nodeAddress top = NULL;

// Function to push an element into the stack
void push(int data){
    nodeAddress temp = (nodeAddress)malloc(sizeof(struct stack_LL));
    temp->data = data;
    temp->next = NULL;
    if(top == NULL){
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
}
// Function to pop an element from the stack
void pop(){
    if(top == NULL){
        printf("\nStack Underflow");
    }
    else{
        nodeAddress temp = top;
        printf("\nThe popped element is %d", temp->data);
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
}
// Function to display the elements in the stack
void display(){
    nodeAddress current = top;
    if(top == NULL){
        printf("\nStack is empty/Underflow");
    }
    else{
        printf("\nThe elements in the stack are: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}
// Function to peek the top element of the stack
void peek(){
    if(top == NULL){
        printf("\nStack is empty/Underflow");
    }
    else{
        printf("\nThe top element is %d", top->data);
    }
}

// Driver code
int main(int argc, char const *argv[])
{
    int choice, data;
    do{
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the data to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    } while (choice != 5);    
    return 0;
}
