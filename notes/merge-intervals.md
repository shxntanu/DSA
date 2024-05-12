# Merge Intervals

The code snippet demonstrates a function that merges overlapping intervals in an array and returns an array of non-overlapping intervals. It first sorts the intervals in ascending order using the merge function. Then, it iterates through each interval and checks if it overlaps with the previous interval. If there is an overlap, it updates the end value of the previous interval to the maximum of the current interval's end value and the previous interval's end value. If there is no overlap, it adds the current interval to the result array. The function utilizes vector manipulation and the max function to achieve this. This code snippet can be useful in scenarios where there is a need to merge overlapping intervals in an array efficiently.

```cpp

/*
Input:
 intervals=[[1,3],[2,6],[8,10],[15,18]]

Output:
 [[1,6],[8,10],[15,18]]
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i][0] <= ans.back()[1]) ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        else ans.push_back(intervals[i]);
    }
    return ans;
}
```
