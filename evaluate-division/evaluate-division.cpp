class Union_Find{
private: 
    vector<int> root;
    vector<int> rank;
    vector<double>multiWeight;
public:

    Union_Find(int sz): root(sz), rank(sz), multiWeight(sz){
        for(int i=0; i<sz ; i++){
            root[i] = i;
            rank[i] = 1;
            multiWeight[i] = 1.0;
        }
    }
    
    pair<int, double> Find(int x){
        if(root[x] == x){
            return {x, 1.0};
        }
        int rootX;
        double multiX;
        tie(rootX, multiX) = Find(root[x]);
        
        return {root[x] = rootX, multiWeight[x] *= multiX};
    }
    
    void Union(int x, int y, double wgt){
        int rootX = Find(x).first;
        int rootY = Find(y).first;
        
        if(rootX == rootY) return;
        
        if(rank[rootX] < rank[rootY]){
            root[rootX] = rootY;
            multiWeight[rootX] = (multiWeight[y]/multiWeight[x])*wgt;
        } else if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
            multiWeight[rootY] = multiWeight[x]/(multiWeight[y]*wgt);
        } else {
            root[rootX] = rootY;
            multiWeight[rootX] = (multiWeight[y]/multiWeight[x])*wgt;
            rank[rootY] += 1;
        }
    }
    
    bool isConnected(int x, int y){
        return (Find(x).first == Find(y).first);
    }
    
};


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int>ids;
        int id = 0;
        vector<double>answers;
        for(auto equation : equations){
            string u = equation[0], v = equation[1];
            if(ids.find(u) == ids.end()) ids[u] = id++;
            if(ids.find(v) == ids.end()) ids[v] = id++;
        }
        
        Union_Find dsu(id);
        
        for(int i=0; i<equations.size(); i++){
            string u = equations[i][0], v = equations[i][1];
            dsu.Union(ids[u], ids[v], values[i]);   
        }
        int i=0;
        for(auto& query : queries){
            if(ids.find(query[0]) == ids.end() || ids.find(query[1]) == ids.end()){
                answers.push_back(-1);
            }
            else{
                int x = ids[query[0]];
                int y = ids[query[1]];
                if(!dsu.isConnected(x, y)) answers.push_back(-1);
                else answers.push_back(dsu.Find(x).second / dsu.Find(y).second);
            }
        }
        
        return answers;
    }
};