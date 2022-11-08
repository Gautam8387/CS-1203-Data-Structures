// WAP to create a min heap using array and perform the deletion operation.
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

/* ========== Insert ========== */
int * heapDelete(int *A, int n, int k){
    // delete an element from the heap
    // we will replace the element to be deleted with the last element of the heap, and then we will heapify the heap
    int i, j;
    for(i = 0; i < n; i++){
        if(A[i] == k){
            A[i] = A[n-1];              // replacing the element to be deleted with the last element of the heap, and then we will heapify the heap
            n--;                        // we can remove the last node of the heap, as it is now a duplicate of the element to be deleted
            break;
        }
    }
    // heapify the heap
    // we will compare the element with its children, and if it is greater than any of its children, we will swap it with the smaller child
    while(2*i+1 < n){                           // while the heap has some element
        j = 2*i+1;
        if(j+1 < n && A[j+1] < A[j]){           // if the right child is smaller than the left child, element in heap is in correct position
            j++;                                // increment j to point to the right child
        }
        if(A[i] > A[j]){                        // if the element is greater than its child, swap them
            swap(&A[i], &A[j]);
            i = j;                              // update the index 
        }
        else{
            break;                              // if the element is smaller than its child, then the heap is in correct position
        }
    }
    return A;    
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

/* ========== Make Minimum Heap ========== */
// Minium Binary Heap has the property that the value of each node is less than or equal to the value of its parent, with the minimum-value element at the root.
// We will swap values in array such that the minimum value is at the top, and the maximum value is at the bottom of the heap.
// If there is an element at position p, then its next two child are at position: 2p+1, 2p+2
// If there is an element at position c, then its parent is at position: floor((c-1))/2

void makeMinHeap(int * A, int n){    
    // We will take each element and compare with its parent, if it is smaller than its parent, we will swap them.   
    int i, j, k;
    for(i = 0; i < n; i++){     // goin through each element
        k = i;                 // k is the current element
        do{                     
            j = (k - 1) / 2;        // j is the parent of k
            if(A[j] > A[k]){        // if parent is greater than child, swap them
                swap(&A[j], &A[k]);
            }
            k = j;                  // k is now the parent of j
        }while(k != 0);             // we will keep doing this until we reach the root element for the current element in the loop
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    // int *A;
    srand(time(NULL)); // seed for random number generator
    int *A;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    A = generateArray(n); 
    printArray(A, n);
    // Now we have a randomly generated array.
    // We will create a minimum heap from this array.
    makeMinHeap(A, n);
    printf("Minimum Heap ");
    printArray(A, n);
    // input th element to be inserted
    
    printf("Enter the element to be deleted: ");
    scanf("%d", &k);

    A = heapDelete(A, n, k);
    printArray(A, n-1);

    free(A);
    return 0;
}
