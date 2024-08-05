class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for(auto i: arr) map[i]++;
        int cnt = 0;
        for(int i=0; i<arr.size(); i++) {
            if(map[arr[i]] == 1) cnt++;
            if(cnt == k) return arr[i];
        }
        return "";
    }
};
