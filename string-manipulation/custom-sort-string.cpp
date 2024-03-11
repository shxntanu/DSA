class Solution {
public:
    string customSortString(string order, string s) {
        string op = "";
        map<char, int> Map;
        for(int i=0; i<s.length(); i++) {
            if(Map.count(s[i]) > 0) 
                Map[s[i]]++;
             else 
                Map[s[i]] = 1;
        }
        for(int i=0; i<order.length(); i++) {
            while(Map[order[i]] > 0) {
                op += order[i];
                Map[order[i]]--;
            }
        }
        for(int i=0;i<s.length(); i++) {
            while(Map[s[i]] > 0) {
                op += s[i];
                Map[s[i]]--;
            }
        }
        return op;
    }
};
