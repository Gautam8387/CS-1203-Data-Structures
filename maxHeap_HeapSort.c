// WAP to create a max heap using array and perform heap sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* ========== Swap ========== */
void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

/* ========== Generate Array ========== */
int * generateArray(int n){ 
    int * t; 
    t = (int *) malloc(n*sizeof(int)); // allocating memory for the array
    if(t){ 
        for (int i = 0; i < n; i++){ 
            t[i] = rand()%1000; // rand()%1000 for a smaller number, all between 0 and 99
        } 
    }
    return t; 
}
/* ========== Print Array ========== */
void printArray(int *a, int n){
    printf("Array = ");
    for (int i = 0; i < n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

/* ========== Make maximum Heap ========== */
// maxium Binary Heap has the property that the value of each node is less than or equal to the value of its parent, with the maximum-value element at the root.
// We will swap values in array such that the maximum value is at the top, and the maximum value is at the bottom of the heap.
// If there is an element at position p, then its next two child are at position: 2p+1, 2p+2
// If there is an element at position c, then its parent is at position: floor((c-1))/2

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


/* ========== Heap Sort ========== */
// Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.
void heapSort(int *A, int n){
    int i;
    for(i = n-1; i > 0; i--){    // we will keep doing this until we reach the root element for the current element in the loop
        swap(&A[0], &A[i]);     // swap the root element with the last element
        makeMaxHeap(A, i);      // make the heap again, but this time we will only go till the last element
    }
}

int main(int argc, char const *argv[])
{
    int n;
    // int *A;
    srand(time(NULL)); // seed for random number generator
    int *A;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    A = generateArray(n); 
    printArray(A, n);
    // Now we have a randomly generated array.
    // We will create a maximum heap from this array.
    makeMaxHeap(A, n);
    printArray(A, n);

    heapSort(A, n);
    printArray(A, n);
    return 0;
}
