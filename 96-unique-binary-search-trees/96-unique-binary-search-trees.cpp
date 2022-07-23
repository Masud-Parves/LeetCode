class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        
        vector<int>DP(n+1, 1);
        
        for(int nodes=1; nodes<=n; nodes++){
            int total = 0;
            for(int root = 1; root<=nodes; root++){
                int left = root-1;
                int right = nodes-root;
                total += DP[left]*DP[right];
            }
            DP[nodes] = total;
        }
        return DP[n];
    }
};