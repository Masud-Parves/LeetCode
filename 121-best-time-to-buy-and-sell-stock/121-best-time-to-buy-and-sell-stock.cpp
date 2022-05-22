class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, minValueTill = INT_MAX;
        for(auto& price : prices){
            if(minValueTill > price)
                minValueTill = price;
            if(max_profit < price-minValueTill){
                max_profit = price-minValueTill;
            }
        }
        return max_profit;
    }
};