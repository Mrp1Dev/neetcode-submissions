class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(true){
            int k = (r+l)/2;
            if(nums[k] == target) return k;
            else if(target > nums[k]) l = k;
            else r = k;

            if(r-l <= 1){
                return nums[r] == target ? r : (nums[l] == target ? l : -1);
            }
        }
    }
};
