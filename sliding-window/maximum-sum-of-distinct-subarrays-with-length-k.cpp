class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long currentSum = 0;
        int begin = 0, end = 0;

        unordered_map<int, int> map;

        while(end < nums.size()) {
            int currNum = nums[end];
            int lastOccurrence = (map.count(currNum) ? map[currNum] : -1);
            
            // if the current window already has the number or the number of 
            // elements in  the window exceed k
            while(begin <= lastOccurrence || end - begin + 1 > k) {
                currentSum -= nums[begin];
                begin++;
            }

            map[currNum] = end;
            currentSum += nums[end];

            // update max sum if no. of elements in current window is k
            if(end - begin + 1 == k) {
                ans = max(ans, currentSum);
            }
            end++;
        }
        return ans;
    }
};
