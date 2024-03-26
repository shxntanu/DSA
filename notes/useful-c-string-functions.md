# Useful String Functions in C

<details>
  <summary>strcmp()</summary>

## strcmp()

C strcmp() is a built-in library function that is used for string comparison. This function takes two strings (array of characters) as arguments, compares these two strings lexicographically, and then returns 0,1, or -1 as the result. It is defined inside <string.h> header file with its prototype as follows:

Syntax: `strcmp(const char *s1, const char *s2)`

Example:
```c
#include <stdio.h>
#include <string.h>
 
int main()
{
    // declaring two same string
    char* first_str = "Hello";
    char* second_str = "Hello";
 
    // printing the strings
    printf("First String: %s\n", first_str);
    printf("Second String: %s\n", second_str);
 
    // printing the return value of the strcmp()
    printf("Return value of strcmp(): %d",
           strcmp(first_str, second_str));  // 0
 
    return 0;
}
```
</details>

<details>
  <summary>strstr()</summary>
 
## strstr()

In C/C++, std::strstr() is a predefined function used for string matching. <string.h> is the header file required for string functions. This function takes two strings s1 and s2 as arguments and finds the first occurrence of the string s2 in the string s1. The process of matching does not include the terminating null-characters(‘\0’), but function stops there. 

Syntax: `char *strstr (const char *s1, const char *s2)`

Example:
```c
#include <stdio.h>
#include <string.h>
 
int main()
{
    // Take any two strings
    char s1[] = "Hello there, World";
    char s2[] = "there";
    char* p;
 
    // Find first occurrence of s2 in s1
    p = strstr(s1, s2);
 
    // Prints the result
    if (p) {
        printf("String found\n");
        printf("First occurrence of string '%s' in '%s' is "
               "'%s'",
               s2, s1, p); // First occurrence of string 'there' in 'Hello there, World' is 'there, World'
    }
    else
        printf("String not found\n");
 
    return 0;
}
```
</details>
