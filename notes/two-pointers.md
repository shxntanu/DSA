# Two Pointers Approach

## Overview
The Two Pointers approach is a technique commonly used to solve problems involving arrays or strings by using two indices to traverse the data structure. This method is efficient for solving problems related to searching, sorting, and manipulating subarrays or substrings.

## Key Concepts
- **Two Pointers**: Typically, two indices (`left` and `right`) are used to represent positions in the array or string.
- **Traversal**: The pointers can move towards each other, away from each other, or in the same direction depending on the problem.
- **Conditions**: The pointers adjust their positions based on specific conditions or criteria to find the solution.

## Steps for Two Pointers Approach
1. **Initialize**:
    - Two pointers (`left` and `right`) to represent positions in the array or string.

2. **Traverse and Adjust**:
    - Move the pointers according to the problem's requirements while checking conditions.

3. **Track the Result**:
    - Update the result based on the conditions met during traversal.

## Example: Find Two Numbers That Add Up to a Target Sum

### Problem
Given a sorted array of integers and a target sum, find two numbers in the array that add up to the target sum. Assume there is exactly one solution.

### Code Implementation

```c
#include <stdio.h>

// Function to find two numbers that add up to the target sum
void findTwoSum(int* arr, int n, int target, int* result) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            result[0] = arr[left];
            result[1] = arr[right];
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result[2];

    findTwoSum(arr, n, target, result);

    printf("The two numbers that add up to %d are: %d and %d\n", target, result[0], result[1]);

    return 0;
}
```

## Explanation

1. Initialize Variables:
    - `left` is set to the beginning of the array.
    - `right` is set to the end of the array.

2. Traverse and Adjust:
    - Calculate the sum of the elements at the `left` and `right` pointers.
    - If the sum equals the `target`, store the elements in the result array and return.
    - If the sum is less than the `target`, move the `left` pointer to the right to increase the `sum`.
    - If the sum is greater than the target, move the `right` pointer to the left to decrease the `sum`.

3. Track the Result:
    - The `result` is stored in the result array once the target sum is found.

## Advantages of Two Pointers

- Efficiency: Often results in O(n) time complexity for many problems, making it very efficient.
- Simplicity: Provides a clear and concise way to handle problems involving pairs of elements or subarrays.
