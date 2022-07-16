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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) {
            return -1;
        }
        
        TreeNode* curr = root;
        stack<TreeNode*>stack;
        stack.push(curr);
        while(!stack.empty() or curr != NULL){
            if(curr != NULL){
                stack.push(curr);
                curr = curr->left;
            } else {
                curr = stack.top();
                stack.pop();
                k--;
                if(k == 0) return curr->val;
                curr = curr->right;
            }
        }
        return -1;
    }
};