class Solution {
private:
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, -1, 1};
    
    bool isValid(int r, int c, vector<vector<int>>& forest){
        return (r>=0 && r<forest.size() && c>=0 && c<forest[0].size() && forest[r][c]!=0);
    }
    
    int bfs(int sr, int sc, int dr, int dc, vector<vector<int>>& forest){
        int rows = forest.size(), cols = forest[0].size();
        int level = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        queue<pair<int, int>> todo;
        todo.push({sr, sc});
        visited[sr][sc] = true;
        
        while(!todo.empty()){
            int size = todo.size();
            for(int k=0; k<size; k++){
                auto cell = todo.front();
                todo.pop();
                int ur = cell.first;
                int uc = cell.second;

                if(ur == dr && uc == dc) return level;

                for(int i=0; i<4; i++){
                    int vr = ur + fx[i];
                    int vc = uc + fy[i];

                    if(isValid(vr, vc, forest) == true && visited[vr][vc] == false){
                        visited[vr][vc] = true;
                        todo.push({vr, vc});
                    }
                }
            }
            level++;
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest[0][0] == 0) return -1;
        int rows = forest.size(), cols = forest[0].size();
        
        vector<vector<int>> trees;
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(forest[r][c]>1){
                    trees.push_back({forest[r][c], r, c});
                }
            }
        }
        
        sort(trees.begin(), trees.end());
        int x = 0, y = 0;
        int steps = 0;
        for(auto& tree : trees){
            int ret = bfs(x, y, tree[1], tree[2], forest);
            if(ret == -1) return -1;
            steps += ret;
            x = tree[1];
            y = tree[2];
        }
        
        return steps;
    }
};