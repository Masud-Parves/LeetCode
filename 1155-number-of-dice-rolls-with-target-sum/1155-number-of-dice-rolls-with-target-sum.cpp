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
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> cache(n, vector<int>(target+1, -1));
        return getWaysRollsToTarget(0, n, k, target, cache);
    }
};