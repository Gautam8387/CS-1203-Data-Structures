/*
1-b: [10 points] Assume you have an array f of length nf, and an array b of length nb, each containing
the integers you need to check for to print fizz and buzz.
So, for each integer in your input array a of length m, you need to check if it’s divisible by
something in f. If so, you should print “fizz”; if it’s divisible by something in b, you should
print “buzz”; and if it is divisible by something in f and b, you should print “fizzbuzz”. (The
previous question has f = [3,5] and b = [11,13], and both nf and nb are 2.) You may assume
there are no repetitions in the arrays and nothing appears in both.
void advancedFizzBuzz(int *a, int m, int *b, int nb, int *f, int nf)
{
    // Your code goes here
}

*/

#include <stdio.h>
void advancedFizzBuzz(int *a, int m, int *b, int nb, int *f, int nf){
    int i, j, k;
    // We will use loops within loop to check the conditions (which will have logical AND and OR between them).
    int counter_f = 0;
    int counter_b = 0;
    for(int i=0; i<m; i++){
        // traverse through whole array
        for(int j=0; j<nf; j++){
            // check for each element in the f and b
            // prints “fizzbuzz” if it’s divisible by values both in f and b
            if(a[i]%f[j]==0){
                counter_f++;
            }
        }
        for(int k=0; k<nb; k++){
            // prints “buzz” if it’s divisible by values in b
            if(a[i]%b[k]==0){
                counter_b++;
            }
        }
        if(counter_f>0 && counter_b>0){
            printf("fizzbuzz ");
        }
        else if(counter_f>0){
            printf("fizz ");
        }
        else if(counter_b>0){
            printf("buzz ");
        }
        else{
            printf("%d ", a[i]);
        }
        counter_f = 0;
        counter_b = 0;
    } 
}

int main(){
    int a[11] = {33, 2, 3, 4, 5, 6, 17, 48, 99, 10, 26};
    int b[2] = {11, 2};
    int f[3] = {3, 13, 7};
    advancedFizzBuzz(a, 11, b, 2, f, 3);
    return 0;
}