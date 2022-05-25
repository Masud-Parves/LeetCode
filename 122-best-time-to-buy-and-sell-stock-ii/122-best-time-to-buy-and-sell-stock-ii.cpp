class Solution {
public:
    
    int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>& DP){
        
        if(idx == prices.size()){
            return 0;
        }
        
        
        int &cache = DP[idx][buy];
        if(cache != -1) return cache;
        
        if(buy == 0){
            int way1 = helper(idx+1, buy, prices, DP); // sell
            int way2 = prices[idx] + helper(idx+1, 1-buy, prices, DP); //sell
            cache = max(way1, way2);
        } else {
            int way1 = helper(idx+1, buy, prices, DP); // buy
            int way2 = -prices[idx] + helper(idx+1, 1-buy, prices, DP); // not buy
            cache = max(way1, way2);
        }
        return cache;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>DP(n+1, vector<int>(2, 0));
        
        DP[n][0] = DP[n][1] = 0;
        
        for(int idx = n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                
                if(buy == 1){
                    DP[idx][buy] = max(-prices[idx] + DP[idx+1][1-buy], DP[idx+1][buy]);
                } else {
                    DP[idx][buy] = max(prices[idx] + DP[idx+1][1-buy], DP[idx+1][buy]);
                }
            }
        }
        
        return DP[0][1];
    }
};