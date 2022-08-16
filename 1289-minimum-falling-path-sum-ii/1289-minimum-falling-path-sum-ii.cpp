class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> DP(n+1, vector<int>(n+1, INT_MAX/2));
        int result = INT_MAX;
        for(int i=0; i<n; i++){
            DP[0][i] = grid[0][i];
        }

        for(int r=1; r<n ; r++){
            for(int p=0; p<n; p++){
                for(int c=0; c<n; c++){
                    if(p==c) continue;
                    DP[r][c] = min(DP[r][c], grid[r][c] + DP[r-1][p]);
                }
            }
        }

        for(int c=0; c<n; c++){
            result = min(result, DP[n-1][c]);
        }
        return result;
    }
};