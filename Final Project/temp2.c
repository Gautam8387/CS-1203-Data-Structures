#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {
 
  // One of the input characters
  char data;
 
  // Frequency of the character
  unsigned freq;
 
  // Left and right child of this node
  struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of
// min heap (or Hufmman tree) nodes
struct MinHeap {
 
  // Current size of min heap
  unsigned size;
 
  // capacity of min heap
  unsigned capacity;
 
  // Array of minheap node pointers
  struct MinHeapNode** array;
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq)
{
  struct MinHeapNode* temp
      = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));
 
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
 
  return temp;
}

// A utility function to create
// a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)
{
 
  struct MinHeap* minHeap= (struct MinHeap*)malloc(sizeof(struct MinHeap));
 
  // current size is 0
  minHeap->size = 0;
 
  minHeap->capacity = capacity;
 
  minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
  return minHeap;
}

// A utility function to
// swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b){
  struct MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)
{
 
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;
 
  if (left < minHeap->size
      && minHeap->array[left]->freq
         < minHeap->array[smallest]->freq)
    smallest = left;
 
  if (right < minHeap->size
      && minHeap->array[right]->freq
         < minHeap->array[smallest]->freq)
    smallest = right;
 
  if (smallest != idx) {
    swapMinHeapNode(&minHeap->array[smallest],
                    &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

// A utility function to check
// if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{
 
  return (minHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
 
  struct MinHeapNode* temp = minHeap->array[0];
  minHeap->array[0]
      = minHeap->array[minHeap->size - 1];
 
  --minHeap->size;
  minHeapify(minHeap, 0);
 
  return temp;
}

// A utility function to insert
// a new node to Min Heap
int insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode){
 
  ++minHeap->size;
  int i = minHeap->size - 1;
 
  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
 
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
 
  minHeap->array[i] = minHeapNode;
}

// A standard funvtion to build min heap
void buildMinHeap(struct MinHeap* minHeap)
{
 
  int n = minHeap->size - 1;
  int i;
 
  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

// A utility function to print an array of size n
int printArr(int arr[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", arr[i]);
 
  printf("\n");
}

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)
{
 
  return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
 
  struct MinHeap* minHeap = createMinHeap(size);
 
  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(data[i], freq[i]);
 
  minHeap->size = size;
  buildMinHeap(minHeap);
 
  return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
  struct MinHeapNode *left, *right, *top;
 
  // Step 1: Create a min heap of capacity
  // equal to size. Initially, there are
  // modes equal to size.
  struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
 
  // Iterate while size of heap doesn't become 1
  while (!isSizeOne(minHeap)) {
 
    // Step 2: Extract the two minimum
    // freq items from min heap
    left = extractMin(minHeap);
    right = extractMin(minHeap);
 
    // Step 3: Create a new internal
    // node with frequency equal to the
    // sum of the two nodes frequencies.
    // Make the two extracted node as
    // left and right children of this new node.
    // Add this node to the min heap
    // '$' is a special value for internal nodes, not used
    top = newNode('$', left->freq + right->freq);
 
    top->left = left;
    top->right = right;
 
    insertMinHeap(minHeap, top);
  }
 
  // Step 4: The remaining node is the
  // root node and the tree is complete.
  return extractMin(minHeap);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
 
  // Assign 0 to left edge and recur
  if (root->left) {
 
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }
 
  // Assign 1 to right edge and recur
  if (root->right) {
 
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }
 
  // If this is a leaf node, then
  // it contains one of the input
  // characters, print the character
  // and its code from arr[]
  if (isLeaf(root)) {
 
    printf("%c: ", root->data);
    printArr(arr, top);
  }
}

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
  // Construct Huffman Tree
  struct MinHeapNode* root
      = buildHuffmanTree(data, freq, size);
 
  // Print Huffman codes using
  // the Huffman tree built above
  int arr[MAX_TREE_HT], top = 0;
 
  printCodes(root, arr, top);
}

void getCode(struct MinHeapNode* root, char* codes[], int arr[], int top)
{
  // Assign 0 to left edge and recur
  if (root->left) {
 
    arr[top] = 0;
    getCode(root->left, codes, arr, top + 1);
  }
 
  // Assign 1 to right edge and recur
  if (root->right) {
 
    arr[top] = 1;
    getCode(root->right, codes, arr, top + 1);
  }
 
  // If this is a leaf node, then
  // it contains one of the input
  // characters, store the character
  // and its code from arr[]
  if (isLeaf(root)) {
 
    // Store the character and its code
    // in the codes array
    codes[root->data] = (char*)malloc(sizeof(char) * (top + 1));
    for (int i = 0; i < top; i++)
      codes[root->data][i] = arr[i] + '0';
    codes[root->data][top] = '\0';
  }
}

char* compress(char* str)
{
  // Calculate frequency of each character
  // in the string
  int freq[256] = {0};
  for (int i = 0; str[i]; i++)
    freq[str[i]]++;
 
  // Build Huffman Tree
  struct MinHeapNode* root
      = buildHuffmanTree(str, freq, strlen(str));
 
  // Print Huffman codes using
  // the Huffman tree built above
  int arr[MAX_TREE_HT], top = 0;
 
  // Store Huffman codes in an array
  // and return the array
  char* codes[256];
  getCode(root, codes, arr, top);
 
  // Calculate size of the compressed string
  int size = 0;
  for (int i = 0; str[i]; i++)
    size += strlen(codes[str[i]]);
 
  // Allocate memory for the compressed string
  char* compressed = (char*)malloc(size + 1);
 
  // Compress the string
  int j = 0;
  for (int i = 0; str[i]; i++) {
 
    strcpy(&compressed[j], codes[str[i]]);
    j += strlen(codes[str[i]]);
  }
 
  // Add a null character at the end
  // of the compressed string
  compressed[size] = '\0';
 
  // Return the compressed string
  return compressed;
}

// Function to decompress a string
// using Huffman Coding

char* decompress(char* str, struct MinHeapNode* root)
{
  // Allocate memory for the decompressed string
  char* decompressed = (char*)malloc(strlen(str) + 1);
 
  // Keep track of the current position in the decompressed string
  int j = 0;
 
  // Start from the root of the Huffman Tree
  struct MinHeapNode* current = root;
 
  // Iterate through the compressed string
  for (int i = 0; str[i]; i++) {
 
    // If the current character is a '0',
    // move to the left child of the current node
    if (str[i] == '0')
      current = current->left;
 
    // If the current character is a '1',
    // move to the right child of the current node
    else
      current = current->right;
 
    // If the current node is a leaf node,
    // add its data to the decompressed string
    if (isLeaf(current)) {
 
      decompressed[j++] = current->data;
      current = root;
    }
  }
 
  // Add a null character at the end
  // of the decompressed string
  decompressed[j] = '\0';
 
  // Return the decompressed string
  return decompressed;
}

// char * decompress(char * str, struct MinHeapNode * root){
//     //allocate memory for decompressed string 
//     char * decompressed = (char *)malloc(sizeof(char) * strlen(str));
//     //create a node to traverse the tree
//     struct MinHeapNode * temp = root;
//     //index for decompressed string
//     int index = 0;
//     //traverse the string
//     for(int i = 0; i < strlen(str); i++){
//         //if the character is 0, go left
//         if(str[i] == '0'){
//             temp = temp->left;
//         }
//         //if the character is 1, go right
//         else{
//             temp = temp->right;
//         }
//         //if the node is a leaf, add the character to the decompressed string
//         if(isLeaf(temp)){
//             decompressed[index] = temp->data;
//             index++;
//             temp = root;
//         }
//     }
// }

// // char* decompress(char* str)
// // {
// //   // Build Huffman Tree
// //   struct MinHeapNode* root = buildHuffmanTree(str, freq, strlen(str));
 
// //   // Print Huffman codes using
// //   // the Huffman tree built above
// //   int arr[MAX_TREE_HT], top = 0;
 
// //   // Store Huffman codes in an array
// //   // and return the array
// //   char* codes[256];
// //   getCodes(root, codes, arr, top);
 
// //   // Calculate size of the decompressed string
// //   int size = 0;
// //   for (int i = 0; str[i]; i++)
// //     size += strlen(codes[str[i]]);
 
// //   // Allocate memory for the decompressed string
// //   char* decompressed = (char*)malloc(size + 1);
 
// //   // Decompress the string
// //   int j = 0;
// //   for (int i = 0; str[i]; i++) {
 
// //     strcpy(&decompressed[j], codes[str[i]]);
// //     j += strlen(codes[str[i]]);
// //   }
 
// //   // Add a null character at the end
// //   // of the decompressed string
// //   decompressed[size] = '\0';
 
// //   // Return the decompressed string
// //   return decompressed;
// // }

// Driver program to test above functions
// int main()
// {
//   char str[] = "Hello, world!";
//  // build huffman tree
//     int freq[256] = {0};
//     for (int i = 0; str[i]; i++)
//         freq[str[i]]++;
//     struct MinHeapNode* root = buildHuffmanTree(str, freq, strlen(str));
//     // print huffman codes
//     int arr[MAX_TREE_HT], top = 0;
//     printCodes(root, arr, top);
//     // compress the string
//     char* compressed = compress(str);
//     printf("Compressed string: %s\n", compressed);
//     // decompress the string
//     char* decompressed = decompress(compressed, root);
//     printf("Decompressed string: %s\n", decompressed);

// //   char* compressed = compress(str);
// //   printf("Compressed string: %s\n", compressed);
 
// //   char* decompressed = decompress(compressed);
// //   printf("Decompressed string: %s\n", decompressed);
 
//   return 0;
// }
void printBits(char* str)
{
  for (int i = 0; str[i]; i++) {
    // Convert the character to an int and
    // print its binary representation
    int val = (int)str[i];
    for (int j = 7; j >= 0; j--)
      printf("%d", (val >> j) & 1);
    printf(" ");
  }
  printf("\n");
}


int main()
{
//   char str[] = "Hello, world!";
char * str;
// input a string
printf("Enter a string: ");
gets(str);

  int freq[256] = {0};
    for (int i = 0; str[i]; i++)
        freq[str[i]]++;
  
 
  // Build Huffman Tree
  struct MinHeapNode* root
      = buildHuffmanTree(str, freq, strlen(str));
 
  // print huffman codes
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
 
  // Store Huffman codes in an array
  char* codes[256];
  getCode(root, codes, arr, top);
 
// print string ithout compression in terms of bits
    printf("String in bits: ");
    printBits(str);
    

  // Compress the string
  char* compressed = compress(str);
  printf("Compressed string: %s\n", compressed);
 
  // Decompress the string
  char* decompressed = decompress(compressed, root);
  printf("Decompressed string: %s\n", decompressed);
 
  return 0;
}


