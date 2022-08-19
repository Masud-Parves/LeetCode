class Solution {
private:
    bool isValid(int r, int c, int row, int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX - 100000));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;
                } else {
                    if(i>0) dis[i][j] = min(dis[i][j], dis[i-1][j]+1);
                    if(j>0) dis[i][j] = min(dis[i][j], dis[i][j-1]+1);
                }
            }
        }
                
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;
                } else {
                    if(i<n-1) dis[i][j] = min(dis[i][j], dis[i+1][j]+1);
                    if(j<m-1) dis[i][j] = min(dis[i][j], dis[i][j+1]+1);
                }
            }
        }
        
        return dis;
    }
};