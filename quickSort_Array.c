// WAP to perform quick sort on an array of integers

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* ========== Partition ========== */
int partition(int *arr, int start, int end){
    int pivot = arr[start]; // pivot
    int wall = start; // wall is the first element of the array
    //  The wall moves to the right if the encountered element is lesser than the pivot
    //  The wall stays in the same position if the encountered element is greater than the pivot
    int scout = start+1;        // scout is the next element to wall of the array, it will check all the elements to the either side of the wall
    while(scout <= end){
        if(arr[scout] < pivot){
            wall++;                         // Incement the wall, so that the wall is always one step ahead of the scout and the smaller elements are always to the left of the wall
            int swap_temp = arr[wall];
            arr[wall] = arr[scout];
            arr[scout] = swap_temp;
        }
        scout++;                            // Increment the scout so it check next element
    }
    // by this logic, all the elements to the left of the wall are lesser than the pivot and all the elements to the right of the wall are greater than the pivot
    // bringing the pivot to the correct position
    int swap_temp = arr[wall];
    arr[wall] = arr[start];
    arr[start] = swap_temp;

    return wall;
}

/* ========== Quick Sort ========== */
// As long as my partation function is correct, this should work
// The partation function is correct if it returns the correct position of the pivot, which is the position of the an element in the array, left of which everything is smaller than the pivot and right of which everything is greater than the pivot.
void quickSort(int *arr, int low, int high){
    if(low <= high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

/* ========== Generate Array ========== */
int * generateArray(int n){ // the return should be of integer pointiner. Which returns the starting address of the array
    int * t; // declaring a new address
    t = (int *) malloc(n*sizeof(int)); // allocating memory for the array
    // This entire for loop is only valid if memory has been successfully set.
    //If t is NULL (array space not allocated) do not run the loop (no sense in running)
    if(t){ 
        for (int i = 0; i < n; i++){ 
            t[i] = rand()%1000; // rand()%1000 for a smaller number, all between 0 and 999
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

	quickSort(a, 0, n-1);  // Perform quick sort on a staring from 0 (first element) to n-1 (last element) 
	
    printArray(a, n);

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	return 0;
}
