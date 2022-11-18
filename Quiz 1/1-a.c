/*
1-a: [5 points] Write a program which inputs an integer x and prints “fizz” if it’s divisible by 3 or
5, prints “buzz” if it’s divisible by 11 or 13, and prints “fizzbuzz” if it’s divisible by 33, 39,
55, or 65. It should print the integer itself in all other cases.
    void basicFizzBuzz(int x)
    {
        // Your code goes here0
    }
*/

#include <stdio.h>
// We will follow the simple logic of reminder of the number with 3, 5, 11, 13, 33, 39, 55, 65, and check each of them according to the given question.
// We will use if-else ladder to check the conditions (which will have logical AND and OR between them).
void basicFizzBuzz(int x){
    int counter = 0;
    // prints “fizzbuzz” if it’s divisible by 33, 39, 55, or 65
    if (x % 33 == 0 || x % 39 == 0 || x % 55 == 0 || x % 65 == 0){
        printf("fizzbuzz ");
        counter++;
    }
    // prints “buzz” if it’s divisible by 11 or 13
    else if (x % 11 == 0 || x % 13 == 0){
        printf("buzz ");
        counter++;
    }
    // prints “fizz” if it’s divisible by 3 or 5
    else if (x % 3 == 0 || x % 5 == 0){
        printf("fizz ");
        counter++;
    }
    // prints the integer itself in all other cases
    else{
        if (counter == 0){
            printf("%d", x);
        }
    }
}

int main(){
    // Taking input from the user
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    // Calling the function
    basicFizzBuzz(x);
    return 0;
}