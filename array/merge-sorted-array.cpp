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
