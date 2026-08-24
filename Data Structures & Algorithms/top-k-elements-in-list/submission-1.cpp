class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFreqs = {};
        for(int i = 0; i < nums.size(); i++){
            numFreqs[nums[i]] += 1;
        }
        priority_queue<pair<int, int>> freqNums = {};
        for(auto p : numFreqs){
            freqNums.push(pair(p.second, p.first));
        }
        vector<int> result = {};
        for(int i = 0; i < k; i++){
            result.push_back(freqNums.top().second);
            freqNums.pop();
        }
        return result;
    }
};
