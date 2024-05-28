# Sliding Window Approach

## Overview
The Sliding Window approach is a popular algorithmic technique used to solve problems related to subarrays or substrings in an array or string. This approach is efficient for problems involving the sum, maximum/minimum values, or specific conditions in contiguous subarrays.

## Key Concepts
- **Window**: A subarray or substring that is part of the larger array or string.
- **Fixed Window Size**: The size of the window remains constant throughout the process.
- **Variable Window Size**: The size of the window can change dynamically based on conditions.

## Steps for Sliding Window Approach
1. **Initialize**:
    - Two pointers (`start` and `end`) to represent the boundaries of the window.
    - A variable (`currentSum` or `currentCondition`) to keep track of the current state (e.g., sum, count).

2. **Expand the Window**:
    - Move the `end` pointer to include new elements in the window.

3. **Adjust the Window**:
    - If the current state exceeds a certain condition, move the `start` pointer to shrink the window until the condition is satisfied.

4. **Track the Result**:
    - Update the result based on the current window size or other criteria.

## Example: Longest Subarray with Sum ≤ maxCost

### Problem
Given an integer array and an integer `maxCost`, find the longest subarray whose sum is less than or equal to `maxCost`.

### Code Implementation

```c
#include <stdio.h>

// Function to find the longest subarray with sum less than or equal to maxCost
int longestSubarrayWithMaxCost(int* arr, int n, int maxCost) {
    int start = 0, end = 0;
    int currentSum = 0;
    int maxLength = 0;

    while (end < n) {
        // Add the current element to the currentSum
        currentSum += arr[end];

        // While currentSum exceeds maxCost, shrink the window from the left
        while (currentSum > maxCost && start <= end) {
            currentSum -= arr[start];
            start++;
        }

        // Update the maximum length of the subarray
        maxLength = (end - start + 1 > maxLength) ? (end - start + 1) : maxLength;

        // Move the end pointer to the right
        end++;
    }

    return maxLength;
}

int main() {
    int arr[] = {1, 2, 1, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxCost = 4;

    int maxLength = longestSubarrayWithMaxCost(arr, n, maxCost);

    printf("The longest subarray with sum <= %d is of length: %d\n", maxCost, maxLength);

    return 0;
}
```
