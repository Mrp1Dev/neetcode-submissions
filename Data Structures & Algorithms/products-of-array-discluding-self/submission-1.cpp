class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixArray = {};
        prefixArray.push_back(nums[0]);
        vector<int> prefixArrayR = {};
        prefixArrayR.push_back(nums[nums.size()-1]);
        for(int i = 1; i < nums.size(); i++){
            prefixArray.push_back(nums[i] * prefixArray[i-1]);
            cout << prefixArray[i] << ' ';
        }
        cout << '\n';
        for(int i = 1; i < nums.size(); i++){
            prefixArrayR.push_back(nums[nums.size() - 1 - i] * prefixArrayR[i-1]);
            cout << prefixArrayR[i] << ' ';
        }
        cout << '\n';

        vector<int> output = {};
        for(int i = 0; i < nums.size(); i++){
            int left = i == 0 ? 1 : prefixArray[i-1];
            int right = i == (nums.size() - 1) ? 1 : prefixArrayR[prefixArrayR.size() - 2 - i];
            cout << "L: " << left << " R: " << right << '\n';
            output.push_back(left*right);
        }
        return output;
    }
};
