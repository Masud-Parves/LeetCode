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
    TreeNode* prev;
    bool inorderTraversal(TreeNode* node){
        if(node == NULL) {
            return true;
        }
        
        if(!inorderTraversal(node->left)) return false;
        
        if(prev != NULL && node->val<=prev->val) return false;
        prev = node;
        return inorderTraversal(node->right);
        
        
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        return inorderTraversal(root);
    }
    
};