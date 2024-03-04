class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, temp = 0;
        int lb = 0, ub = tokens.size() - 1;
        while(lb <= ub) {
            if(power >= tokens[lb]) {
                power -= tokens[lb++];
                temp++;
                score = max(score, temp);
            }
            else if(temp > 0) {
                power += tokens[ub--];
                temp--;
            }
            else break;
        }
        return score;
    }
};
