/*

[10 points] Now, given a value of k, print the k smallest elements among the untouched elements.
n is the length of the array.
    void kSmallestAmongUntouched(int *a, int k, int n)
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

/* ========== Sort every third element ========== */
// Performing basic bubble sort but with a gap of 3
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

/* ========== K Smallest ========== */
void kSmallestAmongUntouched(int *a, int k, int n){
    // We will print the k smallest elements among the untouched elements
    // We will sort the array using bubble sort except every third element
    int i, j, temp;
    for(i=0; i<n; i++){

        if((i+1)%3 != 0){
            for(j=i; j<n; j++){
                
                if((j+1)%3 != 0){

                    if(a[i] > a[j]){
                        swap(&a[i], &a[j]);
                    }
                }
            }
        }
    }
    // New array to store the untouched elements
    printf("New Array: ");
    for(i=0; i<n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    // Printing the k smallest elements
    printf("\nThe %d smallest elements are: ", k);
    int counter = 0;
    for(i=0; counter<k; i++){
        if((i+1)%3 != 0){
            printf(i?", %d":"%d", a[i]);
            counter++;
        }
        else{
            printf(", %d", a[i+1]);
            counter++;
            i++;
        }
    }
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

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    kSmallestAmongUntouched(a, k, n);

	free(a);
	return 0;
}

