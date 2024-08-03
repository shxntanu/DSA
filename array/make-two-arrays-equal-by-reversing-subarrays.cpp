class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> frequencyMap;
        for (size_t i = 0; i < target.size(); ++i) {
            ++frequencyMap[target[i]];
            --frequencyMap[arr[i]];
        }
        for(auto x: frequencyMap)
            if(x.second != 0) return false;

        return true;
    }
};
