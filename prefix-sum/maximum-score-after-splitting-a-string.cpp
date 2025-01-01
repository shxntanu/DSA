// Intuition: Answer = Max(ZerosOnLeft + OnesOnRight)
// = Max(ZerosOnLeft + (TotalOnes - OnesOnLeft))
// = Max(ZerosOnLeft - OnesOnLeft) + TotalOnes (as TotalOnes is constant)
class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, m = INT_MIN;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '0') zeros++;
            else ones++;
            if(i < s.length() - 1) m = max(zeros - ones, m);
        }
        return m + ones;
    }
};
