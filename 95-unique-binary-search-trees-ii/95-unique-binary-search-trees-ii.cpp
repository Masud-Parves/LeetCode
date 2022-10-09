class Solution {
private:
    vector<TreeNode*> helper(int start, int end){
        if(start>end){
            return {NULL};
        }
        vector<TreeNode*> result;
        for(int rootVal = start; rootVal<=end; rootVal++){
            vector< TreeNode* > left = helper(start, rootVal-1);
            vector< TreeNode* > right = helper(rootVal+1, end);
            
            for(auto& leftTree : left){
                for(auto& rightTree : right){
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = leftTree;
                    root->right = rightTree;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result = helper(1, n);
        return result;
    }
};