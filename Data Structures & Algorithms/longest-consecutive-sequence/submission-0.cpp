class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet = {};

        for(int i = 0; i < nums.size(); i++){
            numSet.insert(nums[i]);
        }
        int longestConsecutive = 0;
        for(auto num : numSet){
            if(numSet.contains(num-1) == false){
                int consecutive = 1;
                while(true){
                    if(numSet.contains(num+consecutive))
                        consecutive++;
                    else break;
                }
                if (consecutive > longestConsecutive)
                    longestConsecutive = consecutive;
            }
        }
        return longestConsecutive;
    }
};
