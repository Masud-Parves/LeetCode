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

        int leftDepth = depthOfBT(node->left);
        int rightDepth = depthOfBT(node->right);

        return 1 + max(leftDepth, rightDepth);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        int leftDepth = depthOfBT(root->left);
        int rightDepth = depthOfBT(root->right);
        
        if(abs(leftDepth - rightDepth)>1) {
            return false;
        }
        
        bool isLeftBalanced = isBalanced(root->left);
        bool isRightBalanced = isBalanced(root->right);
        return isLeftBalanced && isRightBalanced;
    }
};
