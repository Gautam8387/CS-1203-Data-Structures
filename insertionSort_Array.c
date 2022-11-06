// WAP to perform insertion sort on an array of integers

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* ========== Swap ========== */
// Call By reference for swap procedure
void swap(int * x, int * y){   // p is the position of the max value in the array, swap it with the current last element
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* ========== Generate Array By Insertion Sort ========== */
int * generateArray_insertion(int n){ // the return should be of integer pointiner. Which returns the starting address of the array
    int input;
    int * t; // declaring a new address
    t = (int *) malloc(n*sizeof(int)); // allocating memory for the array
    // This entire for loop is only valid if memory has been successfully set.
    //If t is NULL (array space not allocated) do not run the loop (no sense in running)
    if(t){ 
        for (int i = 0; i < n; i++){ 
            // We are going to insert the new element in the correct position
            printf("Enter the %dth element: ", i+1);
            scanf("%d", &input);
            t[i] = input;
            // Now we are going to insert the new element in the correct position
            // We are going to compare the new element with all the previous elements
            // If the new element is smaller than the previous element, we are going to swap them
            // We are going to do this until the new element is in the correct position
            for(int j = 0; j < i; j++)
            {
                if(t[j]>t[i]){
                    swap(&t[j], &t[i]);     // Call by Reference for swap procedure
                }
            }
            
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

	a = generateArray_insertion(n); // it has to return an address, the begining of an array

	printArray(a, n); // need to send base address of Array and also need to send size (how long) of array as well 

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	return 0;
}
