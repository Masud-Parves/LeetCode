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
    TreeNode* postorderTraversal(TreeNode* node, int& target){
        if(node == NULL){
            return NULL;
        }
        

        TreeNode* left = postorderTraversal(node->left, target);
        TreeNode* right = postorderTraversal(node->right, target);
        
        node->left = left;
        node->right = right;
        if(node->left == NULL && node->right==NULL && node->val == target){
            return NULL;
        }
        
        return node;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL){
            return root;
        }
        
        TreeNode* newRoot = postorderTraversal(root, target);
        return newRoot;
    }
};