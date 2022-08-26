class Solution {
private:
    int dfs(int r, int c, vector<vector<int>>& matrix, int prevVal, vector<vector<int>>& DP){
        if(r<0 or r == matrix.size() or c<0 or c == matrix[0].size() or matrix[r][c]<=prevVal){
            return 0;
        }
        
        int& cache = DP[r][c];
        if(cache != -1){
            return cache;
        }
        
        cache = 0;
        cache = max(cache , 1 + dfs(r+1, c, matrix, matrix[r][c], DP));
        cache = max(cache , 1 + dfs(r-1, c, matrix, matrix[r][c], DP));
        cache = max(cache , 1 + dfs(r, c+1, matrix, matrix[r][c], DP));
        cache = max(cache , 1 + dfs(r, c-1, matrix, matrix[r][c], DP));
        return cache;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> DP(rows, vector<int>(cols, -1));
        int LIP = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(DP[r][c] == -1){
                    LIP = max(LIP, dfs(r, c, matrix, -1,  DP));
                }
            }
        }
        return LIP;        
    }
};