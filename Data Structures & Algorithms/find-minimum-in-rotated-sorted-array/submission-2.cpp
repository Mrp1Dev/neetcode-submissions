class Solution {
public:
    int findMin(vector<int> &nums) {
        // 6 1 2 3 4 5
        int l = 0;
        int r = nums.size() - 1;
        while(r - l > 1){
            int m = l + (r-l)/2;
            if(nums[r] < nums[m]) l = m ;
            else if(nums[m] < nums[l]) r = m ;
            else break;
        } 
        cout << l << ' ' << r << endl;
        return min(nums[l], nums[r]);
    }
};
