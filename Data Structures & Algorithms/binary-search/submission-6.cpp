class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l<=r){
            int k = l + (r-l)/2;
            if(nums[k] == target) return k;
            else if(target > nums[k]) l = k + 1;
            else r = k - 1;
        }
        return -1;
    }
};
