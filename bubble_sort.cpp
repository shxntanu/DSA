/*
Question: https://www.codingninjas.com/studio/problems/bubble-sort_624380

Explanation:

# Iterative Method
1.Process
--> Compare adjacent elements of the array starting from the first element of the array
--> If the element to the left is greater than the element to the right(in case of sorting in ascending order),
    swap them and continue the same iteration for the rest of the elements
--> At the end of each iteration, 1 element gets sorted(the largest element in the then considered array)
--> The array size to be considerd for sorting then becomes 1 element less than the array size in the previous iteration

--------------------------------------------------------------------
2.Time Complexity:
* O(n^2) - Worst case Time Complexity(Based on the number of comparisons and number of swaps made; both of O(n^2))
* O(n) - The case when the array is already sorted "AND" we are using the variable (bool swapped) to indicate in the first iteration
          itself that the array is already sorted and there is no need to sort it further

3.Space Complexity: O(1)
--------------------------------------------------------------------

# Recursive Method
1.Process
--> Perform the first iteration of comparing and swapping the elements just as in the iterative version
--> Then call the same function, but with the size of the array to be 1 less(as 1 element has already been sorted)
--> Stop this procedure when the array size becomes 1(as array of size 1, i.e, single element is already sorted)

--------------------------------------------------------------------
2.Time Complexity: Similar to iterative as the time complexity depends on the number of swaps and number of comparisons which is the same
3.Space Complexity: O(n) --> As Recursion uses stack
--------------------------------------------------------------------

4.How to think(recursion)
--> Firstly we should think about the main logic that is being performed for one of the elements(Comparing and swapping)
--> Perform that logic for one element(for loop in recursive function)
--> Now, this logic is to performed again for the remaining elements(1 less than the previous)
--> Call this function again with the array size to be 1 less than the previous array size
--> Now, think of a base case to stop the recursive calling of the function(if the size of array is 1 -> return)
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Iterative Version
void bubbleSort(vector<int> &arr, int n)
{
    // write your code here
    bool swapped;

    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

// Recursive method
void bubbleSortRecursive(vector<int> &arr, int endIndex)
{

    if (endIndex == 0)
    {
        return;
    }
    for (int i = 0; i < endIndex; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(&arr[i], &arr[i + 1]);
        }
    }
    bubbleSortRecursive(arr, endIndex - 1);
}

int main()
{
    vector<int> vec = {6, 4, 8, 9, 2};
    // bubbleSort(vec, 5);
    bubbleSortRecursive(vec, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}