/*
[5 points] Given a max heap – assuming it is stored in the usual array mechanism – print the
smallest number. n is the size of the heap.
    void returnSmallestNum(int *maxHeap, int n)
        {
        // Your code goes here
        }
*/
#include<stdio.h>
#include<stdlib.h>

// The minimum element will be the element at last row of the heap if it is a balanced Heap.
// If it is not a balanced heap, then the minimum element will be the element will be either of the element to rows which has no further childs
void returnSmallestNum(int *maxHeap, int n){
    //Search for the smallest number in the last row of the heap
    int i, smallestNum;
    smallestNum = maxHeap[1];
    // set current node to the last node in the last row, last element of the array
    int currentNode = n - 1;
    // set parent node to the child of the last node in the last row
    int childNode = currentNode*2 + 1;
    // if the child node is greater than the total number of elements in the array, then the childNode does not exist. 
    while (childNode>n){
        currentNode--;
        childNode = currentNode*2 + 1;
    }
    //search for the smallest number f rom searchPoint to n-1
    for(i=currentNode; i<n; i++){
        if(maxHeap[i]<smallestNum){
            smallestNum = maxHeap[i];
        }
    }
    printf("Smallest Number = %d\n", smallestNum);

}

int main(int argc, char const *argv[])
{
    // Given a max heap, print the third largest number. n is the size of the heap.
    /*
    Array is: Array = 652, 292, 375, 318, 623, 941, 199, 280, 626, 353.
    Heap is: Array = 941, 626, 652, 623, 353, 375, 199, 280, 292, 318.
    */
    int maxHeap[] = {898, 867, 552, 640, 613, 449, 71, 156, 476, 220};
    int n = 10;
    /*
    // For some random array A of size n, first convert the array to maxHeap, and then print the third largest number.
    makeMaxHeap(A, n);
    */
    returnSmallestNum(maxHeap, n);
    return 0;
}

