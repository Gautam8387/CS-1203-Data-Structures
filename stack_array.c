// Write a program to create a stack using array
// A stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
// Mainly the following three basic operations are performed in the stack:
// Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
// Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
// Peek or Top: Returns top element of stack.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10 // Fixintg the size of the stack to 10
int stack[MAX];
int top = -1; // Initially the stack is empty

// Function to push an element into the stack
void push(int data){
    if(top == MAX-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top] = data;
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        printf("The popped element is %d", stack[top]);
        top--;
    }
}

void display(){
    int i;
    if(top == -1){
        printf("Stack is empty/Underflow");
    }
    else{
        printf("The elements in the stack are: ");
        for(i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
    }
}
void peek(){
    if(top == -1){
        printf("Stack is empty/Underflow");
    }
    else{
        printf("The top element is %d", stack[top]);
    }
}



