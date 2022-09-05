class Union_Find{
public:
    Union_Find(int sz):rank(sz), root(sz){
        for(int i=0; i<sz; i++){
            rank[i] = 1;
            root[i] = i;
        }
    }
    
    int Find(int x){
        if(x == root[x]) return x;
        return root[x] = Find(root[x]);
    }
    
    bool Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        vector<int>ret;
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]){
                root[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
            } else {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
            return false;
        }
        return true;
    }
    
private:
    vector<int>root;
    vector<int>rank;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        
        int candidate1 = -1, candidate2 = -1;
        
        vector<int> indegree(N+1, -1);
        for(int i=0; i<N; i++){
            if(indegree[edges[i][1]] != -1){
                candidate1 = i;
                candidate2 = indegree[edges[i][1]];
                break;
            }
            indegree[edges[i][1]] = i;
        }
        
        cout << candidate1 << " " << candidate2 << endl;
        
        Union_Find dsu(N+1);
        vector<int> result;
        for(int i=0; i<N; i++){
            if(candidate1 == i) continue;
            if(dsu.Union(edges[i][0], edges[i][1]) == true){
                cout << "Cycle" << endl;
                if(candidate1 == -1) {
                    result.push_back(edges[i][0]);
                    result.push_back(edges[i][1]);
                }
                else {
                    result.push_back(edges[candidate2][0]);
                    result.push_back(edges[candidate2][1]);
                }
                return result;
            }
        }
        
        return {edges[candidate1][0], edges[candidate1][1]};
    }
};