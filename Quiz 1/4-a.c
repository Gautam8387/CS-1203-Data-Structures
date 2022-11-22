/*
[10 points] Given a max heap, print the third largest number. n is the size of the heap.
    void thirdLargestNum(int *maxHeap,int n)
        {
            // Your code goes here
        }

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void makeMaxHeap(int * A, int n){    
    // We will perform shift down operation to make the heap
    // We will start from the last parent node, and shift down all the way to the root
    int i, j, k;
    for(i = 0; i < n; i++){     // goin through each element
        k = i;                 // k is the current element
        do{                     
            j = (k - 1) / 2;        // j is the parent of k
            if(A[j] < A[k]){        // if parent is greater than child, swap them
                swap(&A[j], &A[k]);
            }
            k = j;                  // k is now the parent of j
        }while(k != 0);             // we will keep doing this until we reach the root element for the current element in the loop
    }
}

void thirdLargestNum(int *maxHeap,int n){
    // Using the logic of Heap Sort. Using my own code: https://www.github.com/Gautam8387/CS-1203-Data-Structures 
    if(n < 3){
        printf("There are less than 3 elements in the heap. Please try again with a larger heap.");
        return;
    }
    int i, thirdNum;
    for(i = n-1; i > (n)-3; i--){    // we will keep doing this until we reach the third largest element for the current element in the loop
        swap(&maxHeap[0], &maxHeap[i]);     // swap the root element with the last element
        makeMaxHeap(maxHeap, i);      // make the heap again, but this time we will only go till the last element
        thirdNum = maxHeap[0];      // the root element will be the third largest element
    }
    
    printf("The third largest element in the heap is: %d", thirdNum);
}

int main(int argc, char const *argv[])
{
    // Given a max heap, print the third largest number. n is the size of the heap.
    /*
    Array is = 652, 292, 375, 318, 623, 941, 199, 280, 626, 353.
    Heap is = 941, 626, 652, 623, 353, 375, 199, 280, 292, 318.
    */
    int maxHeap[] = {10, 9, 7, 8, 6, 5, 4 };
    int n = 7;
    /*
    // For some random array A of size n, first convert the array to maxHeap, and then print the third largest number.
    makeMaxHeap(A, n);
    */
    thirdLargestNum(maxHeap, n);
    return 0;
}
