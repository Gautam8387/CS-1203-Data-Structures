// Write a program to create a stack using array
// A queue is a linear data structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). A good example of queue is any queue of consumers for a resource where the consumer that came first is served first. The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.
// Mainly the following three basic operations are performed in the queue:
// Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition.
// Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition.
// Front: Get the front item from queue.
// Rear: Get the last item from queue.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int rear = -1;
int front = -1;

void enqueue(int data){
    if(rear == MAX-1){
        printf("\nQueue Overflow");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = data;
    }
    else{
        rear++;
        queue[rear] = data;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("\nQueue Underflow");
    }
    else{
        printf("\nThe dequeued element is %d", queue[front]);
        front++;
    }
}

void display(){
    int i;
    if(front == -1 || front > rear){
        printf("\nQueue is empty/Underflow");
    }
    else{
        printf("\nThe elements in the queue are: ");
        for(i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

void Front(){
    if(front == -1 || front > rear){
        printf("\nQueue is empty/Underflow");
    }
    else{
        printf("\nThe front element is %d", queue[front]);
    }
}

void Rear(){
    if(front == -1 || front > rear){
        printf("\nQueue is empty/Underflow");
    }
    else{
        printf("\nThe rear element is %d", queue[rear]);
    }
}




