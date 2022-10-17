// This program is used to understand the scope of pointers.
// It is also useful in understanding the different types of memory allocation, Why and How declaring a variable during a function (stack memory) is different from declaring a variable using malloc() function (heap memory)

#include <stdio.h>
#include <stdlib.h>

int * blah(int val){
	int x;
	int * pointer = &x;
	x = val * val;
	return pointer;
	// The problem with this program is that it is not going to return a pointer to a valid location
	// The moment this function ends, x house is destroyed. Pointer still has an address, the value is still there but the house at the address does not exists
	// When int * blah ends, it is returning the VALUE OF THE pointer (the address stored) but nothing else from that function is preserved 
	// On the other hand, if I had malloced the value, it won't be destroyed by the compiler on exit

}

int main(int argc, char **argv){
	int * b = blah(5);
	printf("%d.\n", *b); // The danger here is that your compiler is not going to shout at you. 
	return 0;
}
