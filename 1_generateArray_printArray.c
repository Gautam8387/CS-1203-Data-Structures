// A Simple program explaining everything on how to generate and print array.
// Array is generated in heap using the malloc() function for memory allocation

#include <stdio.h>
#include <stdlib.h>


int * generateArray(int n){ // the return should be of integer pointer. Which returns the starting address of the array
	int * t; // declaring a new address
	
	// This is okay but not quite robust code. What is n is negative? What if n is too big, it tries to allocate and it fails.  

	t = malloc( n*sizeof(int) );

	// This entire for loop is only valid if memory has been successfully set.
	//If t is NULL (array space not allocated) do not run the loop (no sense in running)
	if(t){ 
		for (int i = 0; i < n; i++){ t[i] = i; }
		}

	return t;
}

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

int main(int argc, char **argv){
	int * a;
	int n = 10;

	a = generateArray(n); // function generateArray() return an address, the begining of an array, stored in a

	printArray(a, n); // need to send base address of Array and also need to send size (how long) of array as well  

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	return 0;
}
