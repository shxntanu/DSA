# Useful String Functions in C

## strcmp()

C strcmp() is a built-in library function that is used for string comparison. This function takes two strings (array of characters) as arguments, compares these two strings lexicographically, and then returns 0,1, or -1 as the result. It is defined inside <string.h> header file with its prototype as follows:

Syntax: `strcmp(const char *__s1, const char *__s2)`

Example:
```c
#include <stdio.h>
#include <string.h>
 
int main()
{
    // declaring two same string
    char* first_str = "Geeks";
    char* second_str = "Geeks";
 
    // printing the strings
    printf("First String: %s\n", first_str);
    printf("Second String: %s\n", second_str);
 
    // printing the return value of the strcmp()
    printf("Return value of strcmp(): %d",
           strcmp(first_str, second_str));  // 0
 
    return 0;
}
```
