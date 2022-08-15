class Solution {
private:
    int helper(int r, int c, int row, int col, vector<vector<int>>& DP){
        if(r<0 || r==row || c<0 || c==col) return 0;
        if(r == row-1 && c == col-1){
            return 1;
        }

        int& cache = DP[r][c];
        if(cache != -1){
            return cache;
        }

        int way1 = helper(r, c+1, row, col, DP);
        int way2 = helper(r+1, c, row, col, DP);
        return cache = (way1+way2);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, -1));
        return helper(0, 0, m, n, DP);
    }
};