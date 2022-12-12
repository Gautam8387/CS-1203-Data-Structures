#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* compress(char* str, char** codes, int size)
{
  // Allocate memory for the compressed string
  char* compressed = (char*)malloc(strlen(str) + 1);
 
  // Compress the string
  int j = 0;
  for (int i = 0; str[i]; i++) {
 
    strcpy(&compressed[j], codes[str[i]]);
    j += strlen(codes[str[i]]);
  }
 
  // Add a null character at the end
  // of the compressed string
  compressed[size] = '\0';
 
  // Return the compressed string
  return compressed;
}


int main(){
    char str[] = "Hello, world!";
 
char* codes[] = { "000", "001", "010", "011", "100", "101", "110", "111" };
 
char* compressed = compress(str, codes, 8);
printf("Compressed string: %s\n", compressed);
 
free(compressed);
}