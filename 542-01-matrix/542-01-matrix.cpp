class Solution {
private:
    bool isValid(int r, int c, int row, int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>>Q;
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;
                    Q.push({i, j});
                }
            }
        }
        int fx[4] = {1, -1, 0, 0};
        int fy[4] = {0, 0, 1, -1};
        while(!Q.empty()){
            int ux = Q.front().first;
            int uy = Q.front().second;
            Q.pop();
            
            for(int i=0; i<4; i++){
                int vx = ux + fx[i];
                int vy = uy + fy[i];
                if(isValid(vx, vy, n, m)){
                    if(dis[vx][vy] > 1 + dis[ux][uy]){
                        dis[vx][vy] = 1 + dis[ux][uy];
                        Q.push({vx, vy});
                    }
                }
            }
        }
        return dis;
    }
};