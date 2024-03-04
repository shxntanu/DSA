/*
#Question Link: https://www.codingninjas.com/studio/problems/sorted-array_6613259

#Explanation:

We have to return an array which consists of the union of 2 sorted arrays

Method 1: (Use Set)
* Set removes duplicate entries and stores elements in the sorted order as well(not unordered_set)
* Then we can transfer all the elements from the set to the array

Method 2: (Use 2 pointer)
* Take 2 pointers i and j for vector a and b respectively
* Check for the smallest element while comparing elements in both the arrays as we need the resulted union Array in a sorted manner
* Before inserting the element in the resultant union array, check whether that element is already present in the resultant union array or not
* If it is present then do not insert and continue the process for other elements

* NOTE:
--> If we are checking whether the element is present in the array or not, we might tend to end up in a runtime error
--> as initially there wont be any element present in the array to compare;
--> So, we will have to add this condition, {c.size() == 0} || c.back() != b[j];  to perform the check initially

*/

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Write your code here
    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;

    vector<int> c;
    int k = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            if (c.size() == 0 || c.back() != a[i])
            {
                c.push_back(a[i]);
            }
            i++;
        }
        else if (a[i] > b[j])
        {
            if (c.size() == 0 || c.back() != b[j])
            {
                c.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (c.size() == 0 || c.back() != a[i])
        {
            c.push_back(a[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (c.size() == 0 || c.back() != b[j])
        {
            c.push_back(b[j]);
        }
        j++;
    }

    return c;
}