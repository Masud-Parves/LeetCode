class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int row = height.size(), col = height[0].size();
        int waterVolume = 0;
        
        
        priority_queue< pair<int, pair<int, int>>,vector<pair<int,
                        pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        for(int r=0; r<row; r++){
            for(int c=0; c<col ; c++){
                if(r==0 || r==row-1 || c==0 || c==col-1){
                    pq.push({height[r][c], {r, c}});
                    visited[r][c] = true;
                }
            }
        }

        int fx[4]= {1,-1,0,0};
        int fy[4]= {0,0,1,-1};
        int minHeight = 0;
        while(!pq.empty()){
            int currHeight = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            
            pq.pop();
            minHeight = max(currHeight, minHeight);
            
            for(int i=0; i<4; i++){
                int nr = r + fx[i];
                int nc = c + fy[i];
                
                if(nr>=0 && nr<row && nc>=0 && nc<col && visited[nr][nc] == false){
                    pq.push({height[nr][nc], {nr, nc}});
                    visited[nr][nc] = true;
                    if(height[nr][nc]<minHeight){
                        waterVolume += (minHeight-height[nr][nc]);
                    }
                }
            }

        }
        
        return waterVolume;
    }
};