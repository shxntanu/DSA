class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int lb = 0, ub = height.size() - 1;
        int vol = 0;
        while(lb < ub) {
            vol = max(vol, min(height[lb], height[ub]) * (ub - lb));
            if(height[lb] < height[ub]) lb++;
            else ub--;
        }
        return vol;
    }
};
