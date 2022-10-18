// This program explains and implements bubble sort in arrays
// The array is generated using malloc() function and has random integers as values


#include <stdio.h>
#include <stdlib.h>
#include <time.h> // need time.h to use srand (generate random numbers)


/* ========== Bubble Sort ========== */
void bubbleSort(int * a, int n){
	// Bubble sort starts on the left hand side and compares first two people and the taller moves to right. Then compare the next two people. Compare (0,1) (1,2) (2,3) (3,4) ...
	int done, i, temp, swap; 
	// done = simply counts the number of elements that are done
	// swap = simply checkes if swap occurs


/*	// Initially 0 elements are done. We wanna start from the beginning, take the first pair of elements and then take each subsequent pair and swap if they are in wrong order. 
	for(done = 0; done<n; done++) {
		for (i = 0; i < n-1; i++) { // taking pairs of elements, cant take i<n, memory overflow. There is no a[n+1]
			
			if (a[i] > a[i+1]) {
				// Swape these elements since they are in the wrong order
				temp   = a[i];
				a[i]   = a[i+1];
				a[i+1] = temp;
			}

		} // end of the i loop
	} // end of the done loop 		*/

	//Does it make sense to run it n time? The first time you find largest element, it is already bubbled up to the last position. Next time yoy dont want to touch that element. 
	// How many emelemts are we done sorting with? = done

	for(done = 0; done<n; done++) {

		swap = 0; // The entire reason is to dectect if atleast one swap has occured. If we did not do even a single swap that means the array is in the right order
		
		for (i = 0; i < n-1-done; i++) { // taking pairs of elements, cant take i<n, memory overflow. There is no a[n+1]
			
			if (a[i] > a[i+1]) {
				// Swape these elements since they are in the wrong order
				temp   = a[i];
				a[i]   = a[i+1];
				a[i+1] = temp;
				swap   = 1;
			}

		} // end of the i loop
		if(swap == 0)
			break;

	} // end of the done loop 

}

/*	for(done = 0; done<n; done++) {
		for (i = 0; i < n-1-done; i++) {
*/

/* ========== Generate Array ========== */

int * generateArray(int n){ // the return should be of integer pointiner. Which returns the starting address of the array
	int * t; // declaring a new address
	
	// This is okay but not quite robust code. WHat is n is negative. What if n is too big, it tries to allocate and it fails.  

	t = malloc( n*sizeof(int) );

	// This entire for loop is only valid if memory has been successfully set.
	//If t is NULL (array space not allocated) do not run the loop (no sense in running)
	if(t){ 
		for (int i = 0; i < n; i++){ t[i] = rand()%1000; } // rand()%1000 for a smaller number, all between 0 and 999
		}

	return t;
}

/* ========== Print Array ========== */

void printArray(int *a, int n){
	printf("Array = ");
	// Put comas between numbers
	// The first number doesn't have coma before it and last item doesn't have coma after it
	// <CONDITION> ? <EXPRESSION 1> : <EXPRESSION 2>; if Condition is true = Expression 1 else Expression 2
	// When i = 0 (false) do not put a coma. Put coma otherwise
	for (int i = 0; i < n; i++){
		printf(i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n){
	// Basic printing 
	for (int i = 0; i < n; i++){
		printf(" %d ", a[i]);
	}
}

/* ========== main() ========== */

int main(int argc, char **argv){
	int * a;
	int n = 10;

	// Giving srand a seed to generate random numbers. 
	srand(time(NULL)); // time(NULL) gives you the correct current time in seconds since the begining 1978 or something 

	a = generateArray(n); // it has to return an address, the begining of an array

	printArray(a, n); // need to send base address of Array and also need to send size (how long) of array as well 
	bubbleSort(a, n); 
	printArray(a, n);

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	return 0;
}
