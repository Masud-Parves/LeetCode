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
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode* currNode = stk.top();
            stk.pop();
            
            if(currNode->right != NULL){
                stk.push(currNode->right);
            }
            if(currNode->left != NULL){
                stk.push(currNode->left);
            }
            
            if(!stk.empty()){
                currNode->right = stk.top();
            }
            currNode->left = NULL;
        }
        return;
    }
};