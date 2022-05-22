class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> minValue(n);
        minValue[0] = prices[0];
        for(int i=1; i<n ; i++){
            minValue[i] = min(minValue[i-1], prices[i]);
        }
        
        int max_profit = 0;
        
        for(int i=0; i<n; i++){
            max_profit = max(max_profit, prices[i]-minValue[i]);
        }
        return max_profit;
    }
};