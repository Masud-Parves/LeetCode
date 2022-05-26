class Solution {
public:
    
    int calculateMaxProfit(int idx, int buy, int trans, vector<int>& prices, vector<vector<vector<int>>>& DP){
        if(trans == 0 || idx == prices.size()){
            return 0;
        }
        
        int &cache = DP[idx][buy][trans];
        if(cache != -1) {
            return cache;
        }
        
        if(buy == 1) {
            cache = max(-prices[idx] + calculateMaxProfit(idx+1, 0, trans, prices, DP), 
                       calculateMaxProfit(idx+1, 1, trans, prices, DP));
        } else {
            cache = max(prices[idx] + calculateMaxProfit(idx+1, 1, trans-1, prices, DP),
                       calculateMaxProfit(idx+1, 0, trans, prices, DP));
        }
        return cache;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>DP(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        
        int profit = calculateMaxProfit(0, 1, k, prices, DP);
        return profit;
    }
};