class Union_Find{
private:
    vector<int> root;
    int size;
public:
    Union_Find(int n) : root(n){
        for(int i=0; i<n; i++){
            root[i] = i;
        }
        size = n;
    }
    
    int Find(int x){
        if(x == root[x]) return x;
        return root[x] = Find(root[x]);
    }
    
    bool Make_Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX != rootY){
            root[rootY] = rootX;
            size--;
            return true;
        }
        return false;
    }
    
    bool get_component(){
        return size == 1;
    }
    
};


class Solution {
private:
    int mst_cost(int n, vector<vector<int>>& edges, vector<int>& include, vector<int>& exclude){
        Union_Find dsu(n);
        int mst_cost = 0;
        if(!include.empty()){
            dsu.Make_Union(include[0], include[1]);
            mst_cost += include[2];
        }
        
        for(auto& edge : edges){
            if(exclude != edge && dsu.Make_Union(edge[0], edge[1])){
                mst_cost += edge[2];
            }
        }
        return dsu.get_component() == 1 ? mst_cost : INT_MAX;
    }
public:
    static bool cmp(vector<int>&a , vector<int>&b) {
        return a[2] < b[2]; 
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical;
        vector<int> pseudo_critical;
        vector<vector<int>> edges_mst(edges.begin(), edges.end());
        
        sort(edges.begin(), edges.end(), cmp);
        vector<int> empty;
        
        int orginal_mst = mst_cost(n, edges, empty, empty);

        for(int i=0; i<edges_mst.size(); i++){
            int exclude_cost = mst_cost(n, edges, empty, edges_mst[i]);
            if(exclude_cost>orginal_mst){
                critical.push_back(i);
            } else {
                int include_mst = mst_cost(n, edges, edges_mst[i], empty);
                if(include_mst == orginal_mst){
                    pseudo_critical.push_back(i);
                }
            }
        }
        return {critical, pseudo_critical};
    }
};