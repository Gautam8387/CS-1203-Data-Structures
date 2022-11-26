// Write a program to create a simple quad tree program 
// A quadtree is a tree data structure in which each internal node has exactly four children. Quadtree is a two-dimensional version of the binary tree data structure. It is used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions. The regions may be square or rectangular, or may have arbitrary shapes.
// The quadtree data structure is used to represent a two-dimensional space partitioning in a plane. It is a tree data structure in which each internal node has exactly four children. Quadtree is a two-dimensional version of the binary tree data structure. It is used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions. The regions may be square or rectangular, or may have arbitrary shapes.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct quadTree
{
    int data;
    struct quadTree *topLeft;
    struct quadTree *topRight;
    struct quadTree *bottomLeft;
    struct quadTree *bottomRight;
};  

typedef struct quadTree * nodeAddress;

nodeAddress generateQuadTree(int size){
    nodeAddress head = NULL;
    nodeAddress temp = NULL;
    nodeAddress current = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        temp = (nodeAddress)malloc(sizeof(struct quadTree));
        temp->data = rand() % 100;
        temp->topLeft = NULL;
        temp->topRight = NULL;
        temp->bottomLeft = NULL;
        temp->bottomRight = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->topLeft = temp;
            current->topRight = temp;
            current->bottomLeft = temp;
            current->bottomRight = temp;
            current = temp;
        }
    }
    return head;
}

void printQuadTree(nodeAddress head){
    nodeAddress current = head;
    printf("Quad Tree = ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->topLeft;
    }
}

int main(){
    srand(time(0));
    nodeAddress head = generateQuadTree(10);
    printQuadTree(head);
    return 0;
}

