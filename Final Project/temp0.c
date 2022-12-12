// Write a program that compresses a user input string using Huffman coding.
// The program should output the compressed string and the Huffman tree.
// The program should also be able to decompress the compressed string.
// The program should be able to handle any ASCII character.
// The program should be able to handle any string length.
// The program should be able to handle any number of characters.
// The program Huffman Code works as follows:
// 1. The user is prompted to enter a string.
// 2. The program creates a Huffman tree for the string using heaps and Huffman coding.
// 3. The program outputs the Huffman tree in preorder traversal.
// 4. The program outputs the compressed string.
// 5. The program outputs the decompressed string.
// 6. The program outputs the original string.
// 7. The program outputs the compression ratio.
// 8. The program outputs the compression efficiency.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum number of characters in the string
// Create a node structure for the Huffman tree which contains the character, frequency, and left and right pointers.
// The frequency is the number of times the character appears in the string.
// The left and right pointers point to the left and right children of the node.
// Left pointer points to the left child which is the node with the smaller frequency.
// Right pointer points to the right child which is the node with the larger frequency.
// The root of the tree is the node with the largest frequency.
struct node
{
    char data;
    int freq;
    struct node *left, *right;
};
typedef struct node * nodeAddress;

// Create a heap structure which contains the array of nodes and the size of the heap.
// The array of nodes is the array of nodes in the heap.
// The size of the heap is the number of nodes in the heap.
struct heap
{
    nodeAddress array[MAX];
    int size;
};
typedef struct heap * heapAddress;

// Create a function that creates a new node with the given character and frequency.
// The function should return the address of the new node.
nodeAddress newNode(char data, int freq)
{
    nodeAddress temp = (nodeAddress)malloc(sizeof(struct node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Create a function that creates a new heap.
// The function should return the address of the new heap.
heapAddress newHeap()
{
    heapAddress heap = (heapAddress)malloc(sizeof(struct heap));
    heap->size = 0;
    return heap;
}

// Create a function that swaps two nodes in the heap.
// The function should not return anything.
void swap(nodeAddress *a, nodeAddress *b)
{
    nodeAddress temp = *a;
    *a = *b;
    *b = temp;
}

// Create a function that inserts a node into the heap.
// The function should not return anything.
void insert(heapAddress heap, nodeAddress node)
{
    heap->size++;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq)
    {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Create a function that extracts the minimum node from the heap.
// The function should return the address of the minimum node.
nodeAddress extractMin(heapAddress heap)
{
    nodeAddress temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    int i = 0;
    while (i * 2 + 1 < heap->size)
    {
        int j = i * 2 + 1;
        if (j + 1 < heap->size && heap->array[j + 1]->freq < heap->array[j]->freq)
            j++;
        if (heap->array[i]->freq <= heap->array[j]->freq)
            break;
        swap(&heap->array[i], &heap->array[j]);
        i = j;
    }
    return temp;
}

// Create a function that creates a heap from the given array of nodes.
// The function should return the address of the new heap.
heapAddress createHeap(nodeAddress array[], int size)
{
    heapAddress heap = newHeap();
    for (int i = 0; i < size; i++)
        insert(heap, array[i]);
    return heap;
}

// Create a function that builds the Huffman tree from the given array of nodes.
// The function should return the address of the root of the Huffman tree.
nodeAddress buildHuffmanTree(nodeAddress array[], int size)
{
    heapAddress heap = createHeap(array, size);
    while (heap->size != 1)
    {
        nodeAddress left = extractMin(heap);
        nodeAddress right = extractMin(heap);
        nodeAddress temp = newNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        insert(heap, temp);
    }
    return extractMin(heap);
}

// Create a function that prints the Huffman tree in ineorder traversal.
// The function should not return anything.
void printHuffmanTree(nodeAddress root)
{
    if (root)
    {
        printHuffmanTree(root->left);
        printf("%c %d ", root->data, root->freq);
        printHuffmanTree(root->right);
    }
}

// Create a compression function that compresses the given string using Huffman coding.
// The function should print the compressed string.
// It should return a new string which is a pointer to the compressed string.
char *compress(char *string)
{
    int size = strlen(string);
    int freq[256] = {0};
    for (int i = 0; i < size; i++)
        freq[string[i]]++;
    nodeAddress array[256];
    int j = 0;
    for (int i = 0; i < 256; i++)
        if (freq[i])
            array[j++] = newNode(i, freq[i]);
    nodeAddress root = buildHuffmanTree(array, j);
    printHuffmanTree(root);
    // The huffman tree now contains the Huffman codes for each character. Which are stored in the leaf nodes.
    // You can use the Huffman codes to compress the given string.
    // This can be done by replacing each character in the string with its Huffman code.
    // The compressed string should be returned.
    char *compressed = string;
    return compressed; 
}

// Create a decompression function that decompresses the given string using Huffman coding.
// The function should return the decompressed string.
char *decompress(char *string)
{
    return string;
}

int main()
{
    char string[MAX];
    printf("Enter a string: ");
    scanf("%s", string);
    char *compressed = compress(string);
    printf("\nCompressed string: %s", compressed);
    char *decompressed = decompress(compressed);
    printf("\nDecompressed string: %s", decompressed);
    return 0;
}








