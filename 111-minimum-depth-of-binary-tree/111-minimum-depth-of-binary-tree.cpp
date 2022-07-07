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
    int inorderTraversal(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int dl = inorderTraversal(node->left);
        int dr = inorderTraversal(node->right);
        if(dl && dr) {
            return 1+min(dl, dr);
        }
        if(dl){
            return 1 + dl;
        }
        return 1+dr;
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int result = inorderTraversal(root);
        return result;
    }
};