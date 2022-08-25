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
    int goodNodes(TreeNode* root) {
        int result = 0;
        
        queue<pair<TreeNode*, int>>Q;
        Q.push({root, root->val});
        
        while(!Q.empty()){
            TreeNode* node = Q.front().first;
            int tillMax = Q.front().second;
            Q.pop();
            
            if(node->val>=tillMax){
                result++;
                tillMax = node->val;
            }
            
            if(node->left != NULL){
                Q.push({node->left, tillMax});
            }
            if(node->right != NULL){
                Q.push({node->right, tillMax});
            }
        }
        
        return result;
    }
};