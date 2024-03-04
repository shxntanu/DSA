/*
Explanation:

# Process:
1. Consider an element to be the pivot element --> This is the element whose appropriate position is to be found
2. Try to find the correct position of that element in the array by using the partition method
3. After getting the position, replace the pivot element with the element at that position

Now, in one pass, 1 element gets sorted, namely, the pivot

4. Access that position and then perform the same operation recursively for the left and right portion of the array, from (start,j) and (j+1,end)

----------------------------------------------------
# Time Complexity:

// When pivot is the first element
1. Best Case: O(nlogn) --> When the array is partitioned in the middle
2. Worst Case: O(n^2) --> When the array is partitioned at the end points; i.e, the array is ALREADY SORTED

// When pivot is the middle element
1. Best Case: O(nlogn) --> When the array is ALREADY SORTED
2. Worst Case: O(n^2) --> When the partitioning is done at any end(The middle element is the largest or the smallest element)
----------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void swapNumbers(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;

    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swapNumbers(&arr[i], &arr[j]);
    } while (i < j);

    swapNumbers(&arr[start], &arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int start, int end)
{
    int j;
    if (start < end)
    {
        j = partition(arr, start, end);
        quickSort(arr, start, j);
        quickSort(arr, j + 1, end);
    }
}

int main()
{
    vector<int> arr = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT32_MAX};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}