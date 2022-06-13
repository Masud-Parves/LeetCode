class Solution {
private:
    int calculateMinimumPathSum(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& DP){
        
        if(r == triangle.size()){
            return 0;
        }
        
        int &cache = DP[r][c];
        if(cache != -1){
            return cache;
        }
        int way1 , way2;
        way1 = triangle[r][c] + calculateMinimumPathSum(r+1, c, triangle, DP);
        way2 = triangle[r][c] + calculateMinimumPathSum(r+1, c+1, triangle, DP);
        
        return cache = min(way1, way2);
        
        
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        
        vector<vector<int>> DP(row);
        for(int i=0; i< row ; i++){
            DP[i].resize(i+1);
            for(int j=0; j<=i; j++){
                DP[i][j] = -1;
            }
        }
        
        
        return calculateMinimumPathSum(0, 0, triangle, DP);
    }
};