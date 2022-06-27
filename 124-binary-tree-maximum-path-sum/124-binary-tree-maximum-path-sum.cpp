/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
        int getMaxPathSum(TreeNode* node){
        if(node == NULL) {
            return 0;
        }
        
        int leftSum = max(0, getMaxPathSum(node->left));
        int rightSum = max(0, getMaxPathSum(node->right));
        
        return node->val + max(leftSum , rightSum);
    }
    void getMaxPath(TreeNode* node, int& result){
        if(node == NULL) return;
        
        int leftSum = max(0, getMaxPathSum(node->left));
        int rightSum = max(0, getMaxPathSum(node->right));
        
        result = max(result, node->val + leftSum + rightSum);
        getMaxPath(node->left, result);
        getMaxPath(node->right, result);
    }
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        getMaxPath(root, result);
        return result;
    }
};