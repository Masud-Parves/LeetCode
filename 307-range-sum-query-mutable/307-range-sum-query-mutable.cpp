class NumArray {
public:
    int n;
    vector<int> tree;
    void buildTree(int node, int lo, int hi, vector<int>& nums){
        if(lo == hi){
            tree[node] = nums[lo];
            return;
        }
        int mid = (lo + hi)/2;
        buildTree(2*node+1, lo, mid, nums);
        buildTree(2*node+2, mid+1, hi, nums);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    int query(int node, int lo, int hi, int l, int r){
        if(lo>=l && hi<=r){
            return tree[node];
        }
        if(hi<l || lo>r){
            return 0;
        }
        int mid = (lo + hi)/2;
        int left = query(2*node+1, lo, mid, l, r);
        int right = query(2*node+2, mid+1, hi, l, r);
        return left + right;
    }
    
    void updateTree(int node, int lo, int hi, int idx, int val){
        if(lo == hi){
            if(lo == idx)
                tree[node] = val;
            return;
        }
        
        int mid = (lo + hi)/2;
        if(idx<=mid){
            updateTree(2*node+1, lo, mid, idx, val);
        } else {
            updateTree(2*node+2, mid+1, hi, idx, val);
        }
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n==0) return;
        tree.resize(4*n);
        buildTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        if(n==0) return;
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if(n==0) return 0;
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */