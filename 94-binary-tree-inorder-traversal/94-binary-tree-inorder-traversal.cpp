class Solution {
private:
    void inorderTraersal(TreeNode* node, vector<int>& result){
        if(node==NULL) return;
        inorderTraersal(node->left, result);
        result.push_back(node->val);
        inorderTraersal(node->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        inorderTraersal(root, result);
        return result;
    }
};