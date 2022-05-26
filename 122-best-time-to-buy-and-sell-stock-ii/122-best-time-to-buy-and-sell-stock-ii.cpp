class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>DP(n+1, vector<int>(2, 0));
        
        DP[n][0] = DP[n][1] = 0;
        
        for(int idx = n-1; idx>=0; idx--){
            for(int buy = 0; buy<= 1 ; buy++){
                if(buy == 1){
                    DP[idx][buy] = max(-prices[idx] + DP[idx+1][1-buy],
                                      DP[idx+1][buy]);
                } else {
                    DP[idx][buy] = max(prices[idx] + DP[idx+1][1-buy],
                                      DP[idx+1][buy]);
                }
            }
        }
        return DP[0][1];
    }
};