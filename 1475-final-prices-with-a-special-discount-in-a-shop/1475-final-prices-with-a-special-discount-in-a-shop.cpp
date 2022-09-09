class Solution {
public:
    // nearest smallest value for every index
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(n);
        
        stack<int> stk;
        for(int i=n-1; i>=0; i--){
            if(stk.empty()){
                result[i] = prices[i];
                stk.push(i);
            } else {
                
                while(!stk.empty() && prices[i]<prices[stk.top()]){
                    stk.pop();
                }
                
                if(stk.empty()) {
                    result[i] = prices[i];
                    stk.push(i);
                } else {
                    result[i] = prices[i]-prices[stk.top()];
                    stk.push(i);
                }
            }
        }
        return result;
    }
};