class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l = 0;
        int r = l + 1;
        while (l < prices.size() && r < prices.size()) {
            int profit = prices[r] - prices[l];
            if (profit < 0) {
                l++;
                if (l == r) r++;
            } else {
                r++;
            }
            if (profit > maxProfit) maxProfit = profit;
        }

        return maxProfit;
    }
};
