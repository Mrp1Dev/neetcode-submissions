class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            int a = prices[i];
            for(int j = i + 1; j < prices.size(); j++){
                int profit = prices[j] - a;
                if(profit > maxProfit) maxProfit = profit;
            }
        }
        return maxProfit;
    }

};
