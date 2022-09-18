class Union_Find{
public:
    Union_Find(int sz) : root(sz), rank(sz), count(sz){
        for(int i=0; i<sz; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int Find(int x){
        if(x == root[x]){
            return x;
        }
        return root[x] = Find(root[x]);
    }
    
    void Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        
        if(rootX != rootY){
            if(rank[rootX]>rank[rootY]){
                root[rootY] = rootX;
            }else if(rank[rootX] < rank[rootY]){
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }
    
    int getCount(){
        return count;
    }
    
private:
    vector<int>root;
    vector<int>rank;
    int count;
};


class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        if(N==0) return 0;
        
        Union_Find dsu(N);
        
        for(int i=0; i<N ; i++){
            for(int j=1; j<N ; j++){
                if(isConnected[i][j] == 1){
                    dsu.Union(i, j);
                }
            }
        }
        return dsu.getCount();
    }
};