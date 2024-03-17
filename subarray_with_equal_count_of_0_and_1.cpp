#include <bits/stdc++.h>
using namespace std;

// Optimal Approach
/*
Explanation:

# Approach:
* Suppose we have an array --> [0,0,1,0,0,0,1,1]
* Now, we need to find the maximum length of the subarray which consists of equal number of 0's and 1's

* Now, in order to solve this problem, we change all the occurences of 0's to -1's
* So, the array now becomes --> [-1,-1,1,-1,-1,-1,1,1]
* Now, the problem becomes --> Find the length of the subarray containing the sum 0
* We can solve it easily by using the prefixSumMap method

*/
int findMaxLength(vector<int> &nums)
{

    int n = nums.size();

    map<int, int> mpp;

    int sum;
    int maxLength = 0;

    int i = 0;

    while (i < n)
    {
        sum += nums[i] == 0 ? -1 : 1;

        if (sum == 0)
        {
            maxLength = max(maxLength, i + 1);
            i++;
        }
        else if (mpp.find(sum) != mpp.end())
        {
            maxLength = max(maxLength, i - mpp[sum]);
            i++;
        }
        else
        {
            mpp[sum] = i;
            i++;
        }
    }

    return maxLength;
}

// Brute Force
/*
Explanation:

# Approach:
* We will find all the subarrays and calculate the number of 0's and 1's by using the variable count
* 0 --> count++ , 1 --> count--

*/
int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            count = 0;
            for (int k = i; k <= j; k++)
            {
                if (nums[k] == 0)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }

            if (count == 0)
            {
                maxCount = max(j - i + 1, maxCount);
            }
        }
    }

    return maxCount;
}

int main()
{

    vector<int> nums = {0, 1, 1, 0};

    int maxLength = findMaxLength(nums);
    cout << maxLength;
    return 0;
}