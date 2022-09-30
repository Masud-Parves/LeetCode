class Solution {
private:
    int offset = 10000;
    int TreeNode[100001];
    
    void update(int node, int startIdx, int endIdx, int updateIdx){
        if(startIdx>endIdx) return;
        
        if(startIdx == endIdx){
            TreeNode[node] += 1;
            return;
        }
        
        int leftNode = 2*node+1, rightNode = 2*node+2, mid = (startIdx+endIdx)/2;

        if(updateIdx<=mid)update(leftNode, startIdx, mid, updateIdx);
        else update(rightNode, mid+1, endIdx, updateIdx);
        
        TreeNode[node] = TreeNode[leftNode] + TreeNode[rightNode];
        return;        
    }
    
    
    int query(int node, int startIdx, int endIdx, int qStart, int qEnd){
        
        if(qStart>endIdx || qEnd<startIdx){
            return 0;
        }
        if(qStart<=startIdx && qEnd>=endIdx){
            return TreeNode[node];
        }
        
        
        int leftNode = 2*node+1, rightNode = 2*node+2, mid = (startIdx+endIdx)/2;
        int leftCount = query(leftNode, startIdx, mid, qStart, qEnd);
        int rightCount = query(rightNode, mid+1, endIdx, qStart, qEnd);
        
        return leftCount + rightCount;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;
        
        for(int i=n-1; i>=0 ; i--){
            nums[i] += offset;
            int ret = query(0, 0, 20000, 0, nums[i]-1);
            result.push_back(ret);
            update(0, 0, 20000, nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};