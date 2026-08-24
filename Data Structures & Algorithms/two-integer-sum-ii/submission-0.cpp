class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        for(int i = 0; i < numbers.size(); i++){
            int lv = numbers[l];
            int rv = numbers[r];
            if(lv + rv == target){
                return {l+1, r+1};
            } else if (lv + rv < target){
                l++;
            } else {
                r--;
            }
        }
        return {l+1, r+1};
    }
};
