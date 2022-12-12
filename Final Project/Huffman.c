#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum height of the Huffman tree
#define MAX_TREE_HT 100

// Define a structure for Huffman Tree Node, It will be in form of minHeap
struct MinHeapNode {
    // One of the input characters
    char data;
    // Frequency of the character
    unsigned freq;
    // Left and right child of this node
    struct MinHeapNode *left, *right;
};
typedef struct MinHeapNode* MinHeapNodeAddress;

// Define a structure for Min Heap. It is a collection of Huffman leaf nodes
struct MinHeap {
    // Current size of min heap
    unsigned size;
    // capacity of min heap
    unsigned capacity;
    // Array of minheap node pointers
    struct MinHeapNode** array;
};
typedef struct MinHeap* MinHeapAddress;

// A utility function allocate a new min heap node with given character and frequency of the character
MinHeapNodeAddress newNode(char data, unsigned freq)
{
    MinHeapNodeAddress temp = (MinHeapNodeAddress)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// A utility function to create a min heap of given capacity
MinHeapAddress createMinHeap(unsigned capacity)
{
    MinHeapAddress minHeap = (MinHeapAddress)malloc(sizeof(struct MinHeap));
    // current size is 0
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

