// Basics Concepts

#include<stdio.h>
int main(int argc, char **argv){
    int x = 1;
    int y = x++;      // Post Increment //
    int y = ++x;      // Pre Increment // 
    printf("x= %d, y=%d\n", x, y);

    // =========================================

    // printing string and characters
    
    char s_1 = 'v';
    char *s = "abcdefgh";
    *(s+5) = 'x';   // exactly same as saying: s[5] = 'x'
    s[6] = 'y';
    printf("the character *(s+1) is \"%c\".\n", *(s+1));    // this is "b"; *s is an address
    printf("the string s is \"%s\".\n", s);

    const int x_1 = 5;      // declaring a consant variable
    x_1 = 6;                // this statement will result in error, x_1 is a constant
    
    // Understanding Const with Pointers
    int *p = &x_1;        // p holds the address of x_1
    *p = 6;               // this statement changes the value of x_1, even though it is constant. It will show a WARNING
    printf("x_1 = %d\n", x_1);
    printf("*p = %d\n", *p);

    // Constant Strings
    const char * string = "Can't touch this.";  // This string is a pointer variable 
    string = "can't touch this either.";        // String is changed to this new sentence
    printf("%s\n", string);                     // Prints the new string


    return 0;
}
