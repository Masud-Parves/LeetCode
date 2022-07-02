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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        queue<TreeNode*>Q;
        Q.push(root);
        Q.push(root);
        
        while(!Q.empty()){
            TreeNode* leftSubTree = Q.front();
            Q.pop();
            TreeNode* rightSubTree = Q.front();
            Q.pop();
            
            if(leftSubTree->val != rightSubTree->val) return false;
            
            if(leftSubTree->left != NULL && rightSubTree->right != NULL) {
                Q.push(leftSubTree->left);
                Q.push(rightSubTree->right);
            } else if(leftSubTree->left || rightSubTree->right) {
                return false;
            }
            
            if(leftSubTree->right != NULL && rightSubTree->left != NULL) {
                Q.push(leftSubTree->right);
                Q.push(rightSubTree->left);
            } else if(leftSubTree->right || rightSubTree->left) {
                return false;
            }
            
        }
        return true;
    }
};