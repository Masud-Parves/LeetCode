class Solution {
    int helper(int idx, int prev, vector<vector<int>>& costs, vector<vector<int>>& DP, int n){
        if(idx == n-1){
            int minVal = INT_MAX;
            for(int i=0; i<3; i++){
                if(prev == i) continue;
                minVal = min(minVal, costs[idx][i]);
            }
            return minVal;
        }
        
        int& cache = DP[idx][prev];
        if(cache != -1){
            return cache;
        }
        
        cache = INT_MAX/2;
        int ch1, ch2;
        for(int i=0; i<3; i++){
            if(i == prev) continue;
            cache = min(cache, costs[idx][i] + helper(idx+1, i, costs, DP, n));
        }
        return cache;
    }
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> DP(n, vector<int>(4, -1));
        return helper(0, 3, costs, DP, n);
    }
};