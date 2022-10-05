class Solution {
private:
    vector<int> parent, countParent;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    bool make_union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return true;
    
        parent[rootX] = rootY;
        
        return false;
    }
    
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent = vector<int>(n), countParent = vector<int>(n, 0);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                countParent[leftChild[i]]++;
                if(make_union(i, leftChild[i])){
                    return false;
                }
            }
            if(rightChild[i] != -1){
                countParent[rightChild[i]]++;
                if(make_union(i, rightChild[i])){
                    return false;
                }
            }
        }
        
        int component = 0, single_parent_child = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i) component++;
            if(countParent[i] == 1) single_parent_child++;
        }
        //cout << component << " " << single_parent_child << endl;
        return component == 1 && single_parent_child == n-1;
    }
};