class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int N = score.size();

        priority_queue<pair<int, int>> heap;
        for(int i=0; i<N; i++) {
            heap.push({score[i], i});
        }

        vector<string> answer(N);
        int place = 1;
        while(!heap.empty()) {
            int ogIndex = heap.top().second;
            heap.pop();
            if(place == 1) 
                answer[ogIndex] = "Gold Medal";
            else if(place == 2) 
                answer[ogIndex] = "Silver Medal";
            else if(place == 3) 
                answer[ogIndex] = "Bronze Medal";
            else
                answer[ogIndex] = to_string(place);
            place++;
        }
        return answer;
    }
};
