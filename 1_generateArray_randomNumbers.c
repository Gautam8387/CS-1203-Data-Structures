// A simple program that generates an array using malloc() and prints it
// The elements of the array are however the random numbers generated by rand() function

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // need time.h to use srand (generate random numbers)


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

	// Giving srand a seed to generate random numbers. 
	srand(time(NULL)); // time(NULL) gives you the correct current time in seconds since the begining 1978 or something 

	a = generateArray(n); // it has to return an address, the begining of an array

	printArray(a, n); // need to send base address of Array and also need to send size (how long) of array as well  

	// The moment you generate something, immidiately make sure at some point you also free the array a
	free(a);
	return 0;
}
