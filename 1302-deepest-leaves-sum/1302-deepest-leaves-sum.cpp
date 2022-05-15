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
public:
    
    int maxDepth(TreeNode* node){
        
        if(node == NULL) return 0;
        
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        
        return 1+max(leftDepth, rightDepth);
        
    }
    
    void calculateSum(TreeNode* node , int& sum, int depth, int maxDepth){
        
        if(depth == maxDepth){
            sum += node->val;
            return;
        }
        
        if(node->right != NULL){
            calculateSum(node->right, sum, depth+1, maxDepth);
        }
        
        if(node->left != NULL){
            calculateSum(node->left, sum, depth+1, maxDepth);
        }
        return;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        
        int maxD = maxDepth(root);
        
        int sum = 0;
        calculateSum(root, sum, 1, maxD);
        
        return sum;
    }
};