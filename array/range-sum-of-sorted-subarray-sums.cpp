class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1000000007;

        // Create a prefix sum array with the first element 0
        vector<int> prefixSum(n+1,0);
        for(int i=0; i<n; i++)
            prefixSum[i+1] = prefixSum[i] + nums[i];

        // Create a min heap PQ
        priority_queue<int, vector<int>, greater<int>> minHeap;

        /**
         * If we observe, the difference between elements in the prefixsums array gives 
         * the subarray sum of that particular segment of the array. 
         * E.g. Array = [1,4,3]. Prefix Sum array = [0, 0+1, 0+1+4, 0+1+4+3] = [0,1,5,8]
         * 5-0 gives the sum of [1,4]
	       * 5-1 gives the sum of [4].
	       * 8-0 gives the sum of [1,4,3]
	       * 8-1 gives sum of [4,3]
	       * 8-5 gives sum of [3]
         * 
         * Hence push each such sum in the min Heap
         */
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++)
                minHeap.push(prefixSum[i] - prefixSum[j]);
        }

        /**
         * Pick the first `left` to `right` elements
         */
        long long result = 0;
        for(int i=1; i<=right; i++) {
            int s = minHeap.top();
            minHeap.pop();
            if(i >= left)
                result = (result + s) % MOD;
        }

        return result;
    }
};
