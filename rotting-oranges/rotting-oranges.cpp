class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>>Q;
        int fresh = 0;
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 2){
                    Q.push({r, c});
                } else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }
        Q.push({-1, -1}); // mark level end
        int fx[4] = {1, -1, 0, 0};
        int fy[4] = {0, 0, 1, -1};

        int level = -1;
        while(!Q.empty()){
            int ux = Q.front().first;
            int uy = Q.front().second;
            Q.pop();
            
            if(ux == -1) {
                level++;
                if(!Q.empty()){
                    Q.push({-1, -1});
                }
            } else {
                for(int i=0; i<4; i++){
                    int vx = ux + fx[i];
                    int vy = uy + fy[i];
                    if(vx>=0 && vx<row && vy>=0 && vy<col && grid[vx][vy]==1){
                        //cout << vx << " " << vy << " " << grid[vx][vy] << endl;
                        grid[vx][vy] = 2;
                        fresh--;
                        //cout << "yes " << vx << " " << vy << endl;
                        Q.push({vx, vy});
                    }
                }
            }
        }
        return fresh == 0 ? level : -1;
    }
};