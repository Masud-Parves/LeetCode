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
    void leftBoundary(TreeNode* node, vector<int>& result){
        if(node == NULL) {
            return;
        }
        if(node->left == NULL && node->right == NULL) {
            return;
        }
        
        result.push_back(node->val);
        
        if(node->left != NULL) {
            leftBoundary(node->left, result);
        } else if(node->right != NULL) {
            leftBoundary(node->right, result);
        }
    }
    
    void leafBoundary(TreeNode* node, vector<int>& result){
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL){
            result.push_back(node->val);
            return;
        }
        leafBoundary(node->left, result);
        leafBoundary(node->right, result);
    }
    
    void rightBoundary(TreeNode* node, vector<int>& result){
        if(node == NULL) {
            return;
        }
        if(node->left == NULL && node->right == NULL){
           return;
        }
        
        if(node->right != NULL) {
            rightBoundary(node->right, result);
        } else if(node->left != NULL) {
            rightBoundary(node->left, result);
        }
        result.push_back(node->val);
    }
    
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        if(root->left || root->right)
            result.push_back(root->val);
        leftBoundary(root->left, result);
        leafBoundary(root, result);
        rightBoundary(root->right, result);
        return result;
    }
};