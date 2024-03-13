#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return a>b?a:b;
}

int compare(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b);
}

int main() {
    int arr[5] = { 50, 30, 20, 10, 40 };
    int i = 0;
    qsort(arr, 5, sizeof(int), compare);
    printf("Sorted Array: \n");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
