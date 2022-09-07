class SummaryRanges {
public:
    
    map<int, int> root;
    map<int, int> size;
    
    SummaryRanges() {
        root.clear();
        size.clear();
    }
    
    int Find(int x){
        if(root.find(x) == root.end()) {
            root[x] = x;
            size[x] = 1;
        }
        if(x == root[x]) return x;
        return root[x] = Find(root[x]);
    }
    
    void Union_Set(int x, int y){
        if(root.find(x) == root.end()){
            root[x] = x;
            size[x] = 1;
        }
        
        if(root.find(y) == root.end()){
            root[y] = y;
            size[y] = 1;
        }
        
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX == rootY) return;
        
        root[rootY] = rootX;
        size[rootX] += size[rootY];
    }
    
    void addNum(int val) {
        if(root.find(val) == root.end()){
            root[val] = val;
            size[val] = 1;
        } else return;
        
        if(root.find(val+1) != root.end()){
            Union_Set(val, val+1);
        }
        if(root.find(val-1) != root.end()){
            Union_Set(val-1, val);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>intervals;
        
        for(auto [a, b] : root){
            if(a == b){
                intervals.push_back({a, a+size[a]-1});
            }
        }
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */