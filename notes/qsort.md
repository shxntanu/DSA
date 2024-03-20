# qsort in C

Qsort, a powerful tool for sorting arrays in ascending or descending order. It utilizes the efficient Quick Sort algorithm internally.

## Functionality

- Sorts an array of elements of any data type.
- Leverages a user-defined comparison function to determine element order.
- Can be adapted to sort arrays of custom structures or objects.

## Syntax

```c
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
```

## Parameters

- `base`: Pointer to the first element of the array to be sorted.
- `nitems`: Number of elements in the array.
- `size`: Size of each element in bytes.
- `compare`: Pointer to the comparison function that defines the sorting criteria.

## Comparison Function (compare)

- Takes two pointers to constant void as arguments, representing elements to compare.
- Returns an integer value based on the comparison result:
    - Negative value: First element is less than the second.
    - Zero: Elements are equal.
    - Positive value: First element is greater than the second.

## Example (Sorting in Ascending Order)

```c
#include <stdio.h>
#include <stdlib.h>

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
    printf("\n"); // 10, 20, 30, 40, 50
    return 0;
}
```

## Key Points

- qsort modifies the original array in-place.
- `compare` function should be consistent with the desired sorting order.
- For descending order, reverse the comparison logic in `compare`.

## Additional Notes

- The Quick Sort algorithm has an average time complexity of O(n log n), but can perform poorly in the worst case (O(n^2)).
- qsort is a versatile function that can be customized for various sorting needs.
