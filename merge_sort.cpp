// Question: https://www.codingninjas.com/studio/problems/merge-sort_5846

// Explanation:
// This is a recursive method to sort the array using merge sort
// The main process of merge sort is to divide the array into equal parts until the division yields a single element.
// We are doing this because if we need to sort the array using merge sort, we need 2 sorted arrays to merge;
// so as a single element can be considered as an array of 1 element and this array is sorted; we can merge 2 such
// single elements to form a sorted array of size 2;

// and as we repeat this process again and again, combining 2 elements, combining 4 elements, combining 8 elements,
// we will eventually sort the entire array.

//-------------------------------------------------------------------------
// Time Complexity: O(nlogn)
// Space Complecity: O(2n + logn)
// Extra Space required: n + logn (n -> Auxiliary array, logn -> Stack)
//-------------------------------------------------------------------------

void merge(int arr[], int low, int mid, int high, int n)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    int vec[n];

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            vec[k] = arr[j];
            j++;
            k++;
        }
        else
        {
            vec[k] = arr[i];
            i++;
            k++;
        }
    }

    for (; i <= mid; i++)
    {
        vec[k] = arr[i];
        k++;
    }
    for (; j <= high; j++)
    {
        vec[k] = arr[j];
        k++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = vec[i];
    }
}

void mergeSort(int arr[], int l, int r)
{
    // Write Your Code Here
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r, r + 1);
    }
}