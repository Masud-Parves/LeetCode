class Union_Find{
private:
    vector<int> root;    
    
public:
    Union_Find(int sz){
        root.resize(sz);
        for(int i=0; i<sz; i++){
            root[i] = i;
        }
    }
    
    int Find(int x){
        if(root[x] == x) return x;
        return root[x] = Find(root[x]);
    }
    
    void Union(int u, int v){
        int rootX = Find(u);
        int rootY = Find(v);
        if(rootX == rootY) return;
        root[rootX] = rootY;
    }
};

class Solution {

public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        for(int i=1; i<=n; i++){
            pipes.push_back({0, i, wells[i-1]});
        }
        
        sort(pipes.begin(), pipes.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
        
    
        
        Union_Find DSU(n+1);
        int total = 0;
        for(auto& pipe : pipes){
            int rootX = DSU.Find(pipe[0]);
            int rootY = DSU.Find(pipe[1]);
            
            if(rootX != rootY){
                total += pipe[2];
                DSU.Union(pipe[0], pipe[1]);
            }
        }
        return total;
    }
};