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
        int getMaxPathSum(TreeNode* node, int& result){
        if(node == NULL) {
            return 0;
        }
        
        int leftSum = max(0, getMaxPathSum(node->left, result));
        int rightSum = max(0, getMaxPathSum(node->right, result));
        
        result = max(result, node->val + leftSum + rightSum);
            
        return node->val + max(leftSum , rightSum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        getMaxPathSum(root, result);
        return result;
    }
};