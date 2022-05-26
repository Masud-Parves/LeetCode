class Solution {
public:
    
    int calculateMaxProfit(int idx, int buy, vector<int>& prices, int fee, vector<vector<int>>& DP){
        
        if(idx == prices.size()){
            return 0;
        }
        
        
        int &cache = DP[idx][buy];
        if(cache != -1) return cache;
        
        if(buy == 0){
            int way1 = calculateMaxProfit(idx+1, buy, prices, fee, DP); // sell
            int way2 = prices[idx] -fee + calculateMaxProfit(idx+1, 1-buy, prices, fee, DP); //sell
            cache = max(way1, way2);
        } else {
            int way1 = calculateMaxProfit(idx+1, buy, prices, fee, DP); // buy
            int way2 = -prices[idx] + calculateMaxProfit(idx+1, 1-buy, prices,fee, DP); // not buy
            cache = max(way1, way2);
        }
        return cache;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int sz = prices.size();
        vector<vector<int>>DP(sz, vector<int>(2, -1));
        result = calculateMaxProfit(0, 1, prices, fee, DP);
        return result;
    }
};