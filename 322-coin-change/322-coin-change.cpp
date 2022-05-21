class Solution {
public:
    
    
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& DP){
        
        if(amount == 0){
            return 0;
        }
        if(idx < 0) return INT_MAX/2;
        
        
        int &cache = DP[idx][amount];
        if(cache != -1) return cache;
        
        
        cache = solve(idx-1, amount, coins, DP);
        
        if(coins[idx]<=amount){
            cache = min(cache, 1+solve(idx, amount-coins[idx], coins, DP));
        }
        return cache;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> DP(n, vector<int>(amount+1, -1));
        int ret = solve(n-1, amount, coins, DP);
        return ret>=INT_MAX/2 ? -1 : ret;
    }
};