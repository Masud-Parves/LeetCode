class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, minValueTill = INT_MAX;
        for(auto& price : prices){
            minValueTill = min(minValueTill, price);
            max_profit = max(max_profit, price - minValueTill);
        }
        return max_profit;
    }
};