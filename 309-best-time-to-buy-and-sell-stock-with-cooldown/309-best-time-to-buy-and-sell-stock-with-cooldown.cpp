class Solution {
public:
    
    int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>& DP){
        
        if(idx >= prices.size()){
            return 0;
        }
        
        
        int &cache = DP[idx][buy];
        if(cache != -1) return cache;
        
        if(buy == 0){
            int way1 = helper(idx+1, buy, prices, DP); // sell
            int way2 = prices[idx] + helper(idx+2, 1-buy, prices, DP); //sell
            cache = max(way1, way2);
        } else {
            int way1 = helper(idx+1, buy, prices, DP); // buy
            int way2 = -prices[idx] + helper(idx+1, 1-buy, prices, DP); // not buy
            cache = max(way1, way2);
        }
        return cache;
    }
    
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int sz = prices.size();
        vector<vector<int>>DP(sz, vector<int>(2, -1));
        result = helper(0, 1, prices, DP);
        return result;
    }
};