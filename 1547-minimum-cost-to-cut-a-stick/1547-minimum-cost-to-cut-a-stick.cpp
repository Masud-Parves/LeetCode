class Solution {
    
    int mincostUtill(int L, int R, vector<int>& cuts, vector<vector<int>>& dp)
    {
        if(L > R) return 0;
        
        int& cache = dp[L][R];
        if(cache != -1){
            return cache;
        }
        
        int minimumCost = INT_MAX;
        for(int k=L; k<=R; k++) {
            
            int cost =  (cuts[R+1] - cuts[L-1]) + mincostUtill(L, k-1, cuts, dp) +  mincostUtill(k+1, R, cuts, dp);
            minimumCost = min(minimumCost, cost);
        }
        
        return cache = minimumCost;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
               
        return mincostUtill(1, c, cuts, dp);
        
    }
};
