/*
Question Link: https://leetcode.com/problems/insert-interval

Explanation:

# Approach:
* Start with the first vector in the intervals vector
* Check whether it is overlapping with the newInterval or not
    --> If it is not overlapping, then check the cases where the newInterval could be and push it into the new vector 'ans' accordingly
    --> If it is overlapping, then check the appropriate cases where the newInterval is overlapping and perform the action accordingly
* Check for the edge test cases
*/

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{

    int n = intervals.size();
    vector<vector<int>> ans;

    if (n == 0)
    {
        ans.push_back(newInterval);
        return ans;
    }
    int i = 0;
    while (i < n)
    {
        if (newInterval[1] < intervals[i][0] || newInterval[0] > intervals[i][1])
        {
            // Not Overlapping
            if (min(newInterval[1], intervals[i][0]) == newInterval[1])
            {
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                i++;
                break;
            }
            else
            {
                if (i + 1 == n)
                {
                    ans.push_back(intervals[i]);
                    ans.push_back(newInterval);
                    i++;
                    break;
                }
                else
                {
                    ans.push_back(intervals[i]);
                    i++;
                }
            }
        }
        else
        {
            // Overlapping
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);

            i++;

            if (i == n)
            {
                ans.push_back(newInterval);
                return ans;
            }
        }
    }

    for (; i < n; i++)
    {
        ans.push_back(intervals[i]);
    }

    return ans;
}
