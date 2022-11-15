#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Hint1: How integer works with if statement in C
// Hint2: a = b = 5; is equivalent to a = (b = 5); a = func(); which return b=5 
int main(){
    int i;
    int sum = 0;
    for (i = 0; i -= 1000; i++){
        sum += i;
        printf("%d", i);
    }
    printf("Sum = %d\n", i);
    
    ///////////////////////////////////////////////////
    int a[1000];
    int i = -1234567;
    printf("%d\n", a[i]);
    // gdb will give some value for this. GDB is not always right. Need some more assertions to check.
    // Valgrine = other compiler (much better)

    return 0;
}

