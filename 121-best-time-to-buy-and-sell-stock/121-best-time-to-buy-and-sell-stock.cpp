class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> prefixMin(n);
        int maxProfit = 0;
        prefixMin[0] = prices[0];
        
        for(int i=1; i<n; i++){
            maxProfit = max(maxProfit, prices[i]-prefixMin[i-1]);
            prefixMin[i] = min(prefixMin[i-1], prices[i]);
        }
        return maxProfit;
    }
};