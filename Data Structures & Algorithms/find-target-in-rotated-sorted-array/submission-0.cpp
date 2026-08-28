class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[r] <= nums[m]) l = m + 1;
            else r = m;
        }

        int first = r;

        l = 0;
        r = nums.size() - 1;
        auto rotate = [&](int i) { return (i + first) % nums.size();};
        while(l <= r){
            int m = l + (r-l)/2;
            int rotm = rotate(m);
            if(target == nums[rotm]) return rotm;
            else if (target > nums[rotm]) l = m+1;
            else r = m - 1;
        }
        return -1;
    }
};
