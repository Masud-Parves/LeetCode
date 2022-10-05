class Solution {
private:
    vector<int> root;
    int find(int x){
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    bool make_union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;
        root[rootX] = rootY;
        return true;
    }
    
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        root = vector<int>(n);
        
        for(int i=0; i<n; i+=2){
            root[row[i]] = row[i];
            root[row[i+1]] = row[i];
        }
        int count = 0;
        for(int i=0; i<n; i+=2){
            if(make_union(i, i+1)){
                count++;
            }
        }
        return count;
    }
};