class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indicesOfTargets = {};

        for(int i = 0; i < nums.size(); i++){
            auto targetIndex = indicesOfTargets.find(nums[i]);
            if (targetIndex != indicesOfTargets.end()){
                return {targetIndex->second, i};
            } 
            indicesOfTargets[target-nums[i]] = i;
        }
        return {};
    }
};
