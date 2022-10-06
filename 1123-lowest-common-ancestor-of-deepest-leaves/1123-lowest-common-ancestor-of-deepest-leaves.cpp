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
    TreeNode* lca;
    int heightOfBT(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int left = heightOfBT(node->left);
        int right = heightOfBT(node->right);
        return 1 + max(left, right);
    }
    
    bool postorderTraversal(TreeNode* node, int depth, int height){
        if(node == NULL){
            return false;
        }
        if(depth == height){
            lca = node;
            return true;
        }
        
        bool left = postorderTraversal(node->left, depth+1, height);
        bool right = postorderTraversal(node->right, depth+1, height);
        
        if(left == true && right == true){
            lca = node;
            return true;
        }
        return left || right;
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        int depth = heightOfBT(root);
        postorderTraversal(root, 1, depth);        
        return lca;
    }
};