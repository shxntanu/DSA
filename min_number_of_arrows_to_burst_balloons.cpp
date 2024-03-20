#include <bits/stdc++.h>
using namespace std;

/*
V.V.V.Important Question

Question Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

Explanation:

# Concept:
* Sort the 2d vector on the basis of the first element in every vector
* After sorting, check whether 2 intervals are intersecting or not
* If they are intersecting, then only 1 arrow is sufficient to burst both of them
    * After incrementing the count, we will have to figure out the intersecting interval and then we will check further on the interval, whether the interval intersects with the next balloon, then we will be able to burst all the 3 balloons with one single arrow; and continue this process
* If they are not intersecting, then 1 arrow will be required for the previous balloon
    * So, we will increment the count and we will perform the same process of checking the intersection with balloons again
* Finally, we will return the count
*/

class Solution
{
public:
    static bool compareFirstElement(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();

        if (n == 1)
        {
            return 1;
        }
        else
        {
            sort(points.begin(), points.end(), compareFirstElement);

            int count = 0;

            vector<int> key;
            key = points[0];

            int i = 1;
            for (int i = 1; i < points.size(); i++)
            {
                if (points[i][0] <= key[1])
                {
                    n -= 1;
                    key.assign({points[i][0], min(points[i][1], key[1])});
                }
                else
                {
                    key = points[i];
                }
            }

            return n;
        }
    }
};