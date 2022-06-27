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
private:
    int depthOfBT(TreeNode* node){
        if(node == NULL) {
            return 0;
        }
        
        int leftHeight = depthOfBT(node->left);
        int rightHeight = depthOfBT(node->right);
        
        return 1 + max(leftHeight, rightHeight);
    }
    void helper(TreeNode* node, int& result){
        if(node == NULL) return;
        
        int leftHeight = depthOfBT(node->left);
        int rightHeight = depthOfBT(node->right);
        
        result = max(result, leftHeight + rightHeight);
        helper(node->left, result);
        helper(node->right, result);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int result = 0;
        helper(root, result);
        return result;
    }
};