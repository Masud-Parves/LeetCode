class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        while(!stack.empty() || curr != NULL){
            if(curr != NULL){
                stack.push(curr);
                curr = curr->left;
            } else {
                curr = stack.top();
                stack.pop();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return result;
    }
};