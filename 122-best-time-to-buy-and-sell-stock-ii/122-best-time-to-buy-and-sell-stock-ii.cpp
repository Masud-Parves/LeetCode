class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_buy , current_sell, previous_buy, previous_sell;
         previous_buy = previous_sell = 0;
        
        for(int idx = prices.size()-1; idx>=0; idx--){
            for(int buy = 0; buy<= 1 ; buy++){
                if(buy == 1){
                    current_buy = max(-prices[idx] + previous_sell,
                                      previous_buy);
                } else {
                    current_sell = max(prices[idx] + previous_buy,
                                      previous_sell);
                }
            }

            previous_buy = current_buy;
            previous_sell = current_sell;
        }
        return current_buy;
    }
};