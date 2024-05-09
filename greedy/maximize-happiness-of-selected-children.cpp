class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>()); 
        long long ans = 0;
        long long s = 0;
        for(int i=0; i<k; i++) {
            ans += happiness[i];
            if(happiness[i] - i < 0)
                s += happiness[i];
            else
                s += i;
        }
        return ans - s;
    }
};
