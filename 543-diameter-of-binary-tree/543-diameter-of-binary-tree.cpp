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
    int depthOfBT(TreeNode* node, int& result){
        if(node == NULL) {
            return 0;
        }
        
        int leftHeight = depthOfBT(node->left, result);
        int rightHeight = depthOfBT(node->right, result);
        
        result = max(result, leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int result = 0;
        depthOfBT(root, result);
        return result;
    }
};