class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buyPrices = INT_MAX;
        for(int i=0; i<n; i++){
            buyPrices = min(buyPrices, prices[i]);
            profit = max(profit, prices[i]-buyPrices);
        }
        return profit;
    }
};