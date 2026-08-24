class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < nums.size()-2; i++){
            int a = nums[i];
            if(a > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1; 
            int r = nums.size() - 1;
            while (l < r){
                int sum=nums[l] + nums[r];

                if (sum < -a)
                    l++;
                else if (sum > -a)
                    r--;
                else{
                    result.push_back({a, nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                } 
            }
            
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};
