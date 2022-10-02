class Solution {
private:
    int MOD = 1000000007;
    int getWaysRollsToTarget(int idx, int n, int k, int target, vector<vector<int>>& cache){
        if(target == 0 && idx == n){
            return 1;
        }
        if(target<0) return 0;
        if(idx==n && target!=0 || target ==0 && idx != n){
            return 0;
        }
        
        
        int& currState = cache[idx][target];
        if(currState != -1){
            return currState;
        }
        
        int ways = 0;
        for(int i=1; i<=k; i++){
            ways = (ways%MOD + getWaysRollsToTarget(idx+1, n, k, target-i, cache)%MOD)%MOD;
        }
        return currState = ways;
    }
    
    int tabulationSolution(int n, int k, int t, vector<vector<int>>& cache){
        cache[0][0] = 1;
        
        for(int dice = 1; dice<=n; dice++){
            for(int target = 1; target<=t ; target++){
                int ways = 0;
                for(int i=1; i<=k ; i++){
                    if(target-i>=0){
                        ways = (ways%MOD + cache[dice-1][target-i]%MOD)%MOD;
                    }   
                }
                cache[dice][target] = ways;
            }
        }
        return cache[n][t];
    }
    
    int spaceOptimizationSolution(int n, int k, int t){
        vector<int>currRow(t+1, 0), prevRow(t+1, 0);
        prevRow[0] = 1;
        
        for(int dice = 1; dice<=n; dice++){
            for(int target = 1; target<=t ; target++){
                int ways = 0;
                for(int i=1; i<=k ; i++){
                    if(target-i>=0){
                        ways = (ways%MOD + prevRow[target-i]%MOD)%MOD;
                    }   
                }
                currRow[target] = ways;
            }
            prevRow = currRow;
        }
        return prevRow[t];
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> cache(n+1, vector<int>(target+1, 0));
        return tabulationSolution(n, k, target, cache);
    }
};