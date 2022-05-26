class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>DP(n+1, vector<int>(2, 0));
        int current_buy , current_not_buy, previous_buy, previous_not_buy;
         previous_buy = previous_not_buy = 0;
        
        for(int idx = n-1; idx>=0; idx--){
            for(int buy = 0; buy<= 1 ; buy++){
                if(buy == 1){
                    current_buy = max(-prices[idx] + previous_not_buy,
                                      previous_buy);
                } else {
                    current_not_buy = max(prices[idx] + previous_buy,
                                      previous_not_buy);
                }
            }

            previous_buy = current_buy;
            previous_not_buy = current_not_buy;
        }
        return current_buy;
    }
};