// Using qsort
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* numA, const void* numB) {
    const int* num1 = (const int*)numA;
    const int* num2 = (const int*)numB;
    if (*num1 > *num2) return 1;
    else {
        if (*num1 == *num2) return 0;
        else return -1;
    }
}

int maxProductDifference(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    return (nums[numsSize - 1] * nums[numsSize - 2]) - (nums[0] * nums[1]);
}   

// Straightforward approach
int maxProductDifference(int* nums, int numsSize){
    int max1, max2, min1, min2;
    int temp;
    int res;
    int count = 0;
    max1 = max2 = 0;
    min1 = min2 = 10001;

    for (int i = 0; i<numsSize; i++){
        if (nums[i]>max1){
            max1 = nums[i];
            temp = i;
        }
    }
    for (int i = 0; i<numsSize; i++){
        if(nums[i]>max2 && i != temp){
            max2 = nums[i];
        }
    }
    for (int i = 0; i<numsSize; i++){
        if (nums[i]<min1){
            min1 = nums[i];
            temp = i;
        }
    }
    for (int i = 0; i<numsSize; i++){
        if(nums[i]<min2 && i != temp){
            min2 = nums[i];
        }
    }
    printf("%d %d %d %d", max1, max2, min1, min2);
    res = (max1*max2)-(min1*min2);
    return res;
}
