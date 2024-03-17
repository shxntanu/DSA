#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    int i = 0;
    int j = 0;

    long long int product = 1;
    vector<int> answer;

    while (i < n)
    {
        while (j < n)
        {
            if (j == i)
            {
                j++;
            }
            else
            {
                product *= nums[j];
                j++;
            }
        }

        answer.push_back(product);
        product = 1;
        i++;
        j = 0;
    }

    return answer;
}

// Better Solution
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    int product = 1;
    int count = 0;
    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            product *= nums[i];
        }
        else
        {
            count++;
        }
    }

    if (count >= 2)
    {
        product = 0;
    }

    int i = 0;
    while (i < n)
    {
        if (count > 0)
        {
            if (nums[i] != 0)
            {
                answer.push_back(0);
                i++;
            }
            else
            {
                answer.push_back(product);
                i++;
            }
        }
        else
        {
            answer.push_back(product / nums[i]);
            i++;
        }
    }
    return answer;
}

int main()
{
    return 0;
}