// WAP to perform selection sort on an array of integers

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* ========== Find Max Position ========== */
int findMaxPos(int * a, int n){
    int i, maxPos = 0;  // maxPos is the position of the max value in the array
    for(i=1; i<n; i++){ // i starts from 1 because we already have the first element as the max value, as maxPos = 0
        if(a[i] > a[maxPos])
            maxPos = i;     // update the maxPos if a new max value is found
    }
    return maxPos;
}

/* ========== Swap ========== */
void swap(int * a, int p, int n){   // p is the position of the max value in the array, swap it with the current last element
    int temp = a[p];
    a[p] = a[n];
    a[n] = temp;
}

/* ========== Selection Sort ========== */
// we are going to find the highest element in the array and swap it with the last element
void selectionSort(int * a, int n){
    int p; // position of the highest element
    for (int i = 0; i < n; i++)
    {
        p = findMaxPos(a, n-i);     // find the position of the highest element at the i-th iteration
        swap(a, p, n-i-1);          // swap the highest element with the last element at the i-th iteration
    }
    // Assuming the findPosMax() gives the correct position of highest element, the selection sort is correct.
}

/* ========== Generate Array ========== */
int * generateArray(int n){ // the return should be of integer pointiner. Which returns the starting address of the array
    int * t; // declaring a new address
    t = (int *) malloc(n*sizeof(int)); // allocating memory for the array
    // This entire for loop is only valid if memory has been successfully set.
    //If t is NULL (array space not allocated) do not run the loop (no sense in running)
    if(t){ 
        for (int i = 0; i < n; i++){ 
            t[i] = rand()%100; // rand()%1000 for a smaller number, all between 0 and 99
        } 
    }
    return t; // return the address of the array
}

/* ========== Print Array ========== */
void printArray(int *a, int n){
    printf("Array = ");
    // Put comas between numbers
    // The first number doesn't have coma before it and last item doesn't have coma after it
    // When i = 0 (false) do not put a coma. Put coma otherwise
    for (int i = 0; i < n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

/* ========== main() ========== */
int main(int argc, char **argv){
	int * a;
	int n;
    // Input the size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

	// Giving srand a seed to generate random numbers. 
	srand(time(NULL)); // time(NULL) gives you the correct current time in seconds since the begining 1978 or something 

	a = generateArray(n); // it has to return an address, the begining of an array

	printArray(a, n); // need to send base address of Array and also need to send size (how long) of array as well 
	selectionSort(a, n); 
	printArray(a, n);

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	return 0;
}
