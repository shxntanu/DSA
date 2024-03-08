/*
Explanation:

1. Process:
* Firstly transpose the matrix by swapping the elements on both sides of the diagonal
* Now, reverse the order of the elements in each of the rows

2. Time Complexity:
* O(n^2) --> Least time that can be taken to perform this operation as it involves a 2D Matrix

3. How to think
* Firstly, we need to observe the current situation of the matrix and the resultant situation of the matrix(i.e, after rotation)
* After observing, we get to know some things about the relationship between the indexes in both the situations of the matrix
* So, based on this relationship, we think of tranposing the matrix and then reversing the order of elements in each row, thus, we get the desired matrix

*/

#include <bits/stdc++.h>
using namespace std;

void swapElements(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void rotateMatrix(vector<vector<int>> &mat)
{
    // Write your code here.
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swapElements(&mat[i][j], &mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swapElements(&mat[i][j], &mat[i][n - j - 1]);
        }
    }
}

int main()
{
    return 0;
}