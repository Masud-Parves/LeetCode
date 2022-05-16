class Solution {
public:
    
    bool isValid(int r, int c, int row , int col){
        return (r>=0 && r<row && c>=0 && c<col);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int row = grid.size(), col = grid[0].size();
        
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1) return -1;
        
        int dx[] = {0,0,1,1,1,-1,-1,-1};
        int dy[] = {1,-1,1,0,-1,1,0,-1};
        vector<vector<int>>distance(row, vector<int>(col, 0));
        
        queue<pair<int, int>>Q;
        Q.push({0, 0});
        distance[0][0] = 1;
        grid[0][0] = 1;
        while(!Q.empty()){
            int ux = Q.front().first;
            int uy = Q.front().second;
            Q.pop();
            for(int i=0; i<8 ; i++){
                int vx = ux+dx[i];
                int vy = uy+dy[i];
                
                if(isValid(vx, vy, row, col) && grid[vx][vy] == 0){
                    grid[vx][vy] = 1;
                    distance[vx][vy] = distance[ux][uy]+1;
                    Q.push({vx, vy});
                }
            }
        }
        return distance[row-1][col-1] == 0 ? -1 : distance[row-1][col-1];
    }
};