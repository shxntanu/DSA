/*
Question: https://www.codingninjas.com/studio/problems/insertion-sort_624381

Explanation:

# Process:
--> Considering the first element to be sorted, start with the second element as the key
--> Now, start comparing the elements before the key in the array
--> If the elements before key are larger than key, "copy" the element to its successive(arr[j+1] = arr[j])
--> As soon as we get any element smaller than key, we "insert" our key ahead of that element

# Time Complexity: O(n^2) -- Number of Comparisons
# Space Complexity: O(1);
*/

void swapNumbers(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

// Iterative Version
void insertionSort(int arr[], int n)
{
    // write your code here
    int key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Recursive Version
void insertionSortRecursive(int *arr, int n, int beginIndex)
{

    if (beginIndex == n)
    {
        return;
    }
    int key = arr[beginIndex];
    int j = beginIndex - 1;

    while (j >= 0 && key < arr[j])
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;

    insertionSortRecursive(arr, n, beginIndex + 1);
}