class Solution {
    int calculateWays(int idx, int amount, vector<int>& coins, vector<vector<int>>& DP){
        if(amount == 0) return 1;
        if(idx<0 || amount<0){
            return 0;
        }
        
        int & cache = DP[idx][amount];
        if(cache != -1){
            return cache;
        }
        
        int way1 = 0, way2 = 0;
        way1 = calculateWays(idx-1, amount, coins, DP);
        if(coins[idx]<=amount){
            way2 = calculateWays(idx, amount-coins[idx], coins, DP);
        }
        return cache = (way1 + way2);
    }
public:    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) return 1;
        vector<vector<int>>DP(n, vector<int>(amount+1, 0));

        for(int c=0; c<=amount; c++){
        	DP[0][c] = (c%coins[0] == 0);
        }

        for(int idx=1; idx<n; idx++){
        	for(int c=0; c<=amount ; c++){
        		int way1 = DP[idx-1][c], way2=0;
        		if(coins[idx]<=c){
        			way2 = DP[idx][c-coins[idx]];
        		}
                DP[idx][c] = (way1+way2);
        	}
        }

        return DP[n-1][amount];
    }
};