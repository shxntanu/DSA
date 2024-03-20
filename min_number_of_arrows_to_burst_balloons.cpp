#include <bits/stdc++.h>
using namespace std;

/*
V.V.V.Important Question

Question Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

Explanation:

* Main thing to focus on here is; there can be multiple balloons which might be overlapping
* Now, suppose we have 3 balloons that are overlapping and we start iterating in the array
* We check the condition whether the balloons are intersecting or not, if they are intersecting then we are incrementing
    the count by 1 because both the intersecting balloons can be burst using 1 arrow
* Now, if we perform the same operation again on the next pair of balloons, they will also be intersecting because all
    3 are intersecting
    * As they both are intersecting, we increment the count by 1 as they both will require only 1 balloon
* BUT!!!, we are not checking whether the 3rd balloon is intersecting with the first balloon or not
* If we check, we get that we can burst all the 3 balloons using 1 arrow; BUT now the COUNT IS 2, as we have incremented it twice!!

* So, for solving this problem, we need to take in consideration the intersecting interval between the 2 balloons
* and then check the further balloon's intersection with this intersecting interval!!

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