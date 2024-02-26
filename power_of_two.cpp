// Question: https://leetcode.com/problems/power-of-two/description/

/*
Problem Description:
Find whether a number can be represented in the power of two or not

Explanation:
If we try to carefully observe the binary representation of any number which can be represented in the form of 2,
we see that it will always have a single bit as 1, for example:
8 -> 2^3 (3rd bit is 1), 00001000
16 -> 2^4 (4th bit is 1),00010000

And we try to observe the number 1 less than this number, i.e
7 -> 00000111
15 -> 00001111

Now, if we perform the AND operation of 8 and 7, 16 and 15, ....., n and (n-1), we will always get the result as 0
*/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        else
        {
            return (n & (n - 1)) == 0;
        }
    }
};