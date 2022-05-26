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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>DP(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        
        //  base case ;
        for(int buy = 0; buy<=1 ; buy++){
            for(int trans = 0; trans<= 2; trans++){
                DP[n][buy][trans] = 0;
            }
        }
        for(int i=0; i<=n; i++){
            DP[i][0][0] = DP[i][1][0] = 0;
        }
        
        
        for(int idx = n-1; idx>=0 ; idx--){
            for(int buy = 0; buy<=1; buy++){
                for(int trans=1; trans<=2; trans++){
                    if(buy == 1){
                        DP[idx][buy][trans] = max(-prices[idx] + DP[idx+1][1-buy][trans], DP[idx+1][buy][trans]);
                    } else {
                        DP[idx][buy][trans] = max(prices[idx] + DP[idx+1][1-buy][trans-1], DP[idx+1][buy][trans]);
                    }
                }
            }
        }
        return DP[0][1][2];
        //int profit = calculateMaxProfit(0, 1, 2, prices, DP);
        //return profit;
    }
};