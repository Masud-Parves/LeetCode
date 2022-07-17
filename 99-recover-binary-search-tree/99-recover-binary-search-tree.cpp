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
    pair<TreeNode*, TreeNode*>p[2];
    void inorderTraversal(TreeNode* node, vector<TreeNode*>& inorder, TreeNode* &prev, int& invalid){
        if(node == NULL){
            return;
        }
        inorderTraversal(node->left, inorder, prev, invalid);
        if(prev != NULL && (prev->val > node->val)){
            p[invalid] = {prev, node};
            invalid++;
        }
        prev = node;
        inorderTraversal(node->right, inorder, prev, invalid);
    }
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL){
            return;
        }
        vector<TreeNode*> inorder;
        int invalid = 0;
        TreeNode* prev = NULL;
        inorderTraversal(root, inorder, prev, invalid);
        if(invalid == 2){
            swap(p[0].first->val, p[1].second->val);
        } else {
            swap(p[0].first->val, p[0].second->val);
        }
    }
};