class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> lower;
        for(int i = 0; i < temperatures.size(); i++){
                while(!lower.empty() && temperatures[lower.top()] < temperatures[i]){
                    result[lower.top()] = i - lower.top();
                    lower.pop();
                }
                lower.push(i);
        }

        while(!lower.empty()){
            result[lower.top()] = 0;
            lower.pop();
        }
        return result;
    }
};
