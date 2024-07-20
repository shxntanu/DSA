/*
Intuition: Shell Sort

PS: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Approach: Fill nums1 with all elements from nums2 and apply shell sort.

Time complexity: O(log(m+n)) + O(m+n)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m; i<m+n; i++) {
            nums1[i] = nums2[i-m];
        }
        int len = m+n;
        int gap = (len/2) + (len%2);
        while (gap>0) {
            int left = 0;
            int right = left+gap;
            while (right<(m+n)) {
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
                left ++;
                right ++;
            }
            if (gap==1) break;
            gap = (gap/2)+(gap%2);
        }
    }
};
