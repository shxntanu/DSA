#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* numA, const void* numB)
{
    const int* num1 = (const int*)numA;
    const int* num2 = (const int*)numB;

    if (*num1 > *num2) {
        return 1;
    }
    else {
        if (*num1 == *num2)
            return 0;
        else
            return -1;
    }
}

int main()
{
    int arr[5] = { 50, 30, 20, 10, 40 };
    int i = 0;

    qsort(arr, 5, sizeof(int), compare);

    printf("Sorted Array: \n");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
