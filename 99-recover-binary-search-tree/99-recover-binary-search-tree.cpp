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
    void inorderTraversal(TreeNode* node, vector<TreeNode*>& inorder){
        if(node == NULL){
            return;
        }
        inorderTraversal(node->left, inorder);
        inorder.push_back(node);
        inorderTraversal(node->right, inorder);
    }
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL){
            return;
        }
        vector<TreeNode*> inorder;
        inorderTraversal(root, inorder);
        int n = inorder.size();
        int invalid = 0;
        pair<int, int> p[2];
        for(int i=0; i<n-1; i++){
            if(inorder[i]->val > inorder[i+1]->val) {
                p[invalid] = {i , i+1};
                invalid++;
            }
        }
        if(invalid == 2){
            swap(inorder[p[0].first]->val, inorder[p[1].second]->val);
        } else {
            swap(inorder[p[0].first]->val, inorder[p[0].second]->val);
        }
    }
};