/*
[10 points] Given a list of length n (random integers), sort every third element. All other
elements should remain untouched.
    int *sortEveryThirdElement(int *a, int n)
        {
        // Your code goes here
        return a;
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
// Function to swap two elements
// We will swap every third element using bubble sort and incementing the pointer by 3 starting from the first 3rd element (index 2)
int * sortEveryThirdElement(int *a, int n){
    int i, j, temp;
    for(i = 2; i < n; i += 3){
        for(j=i; j<n; j += 3){
            if(a[i] > a[j]){
                swap(&a[i], &a[j]);
            }
        }
    }
    return a;
}

/* ========== Generate Array ========== */
int * generateArray(int n){ 
    int * t; // declaring a new address
    t = (int *) malloc(n*sizeof(int)); // allocating memory to the address
    if(t){ 
        for (int i = 0; i < n; i++){ 
            t[i] = rand()%1000; 
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

/* ========== main() ========== */
int main(int argc, char **argv){
	int * a;
	int n;
    // Input the size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

	// Giving srand a seed to generate random numbers. 
	srand(time(NULL)); 

	a = generateArray(n); 
	printArray(a, n); 

    a = sortEveryThirdElement(a, n);
    printArray(a, n);

	free(a);
	return 0;
}

