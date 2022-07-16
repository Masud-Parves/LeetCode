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
    TreeNode* constructBST(int& taken, int n, vector<int>& preorder, int lower, int upper){
        if(taken == n){
            return NULL;
        }
        
        int nodeVal = preorder[taken];
        
        if(nodeVal<lower || nodeVal>upper){
            return NULL;
        }
        taken++;
        TreeNode* root = new TreeNode(nodeVal);
        
        root->left = constructBST(taken, n, preorder, lower, root->val);
        root->right = constructBST(taken, n, preorder, root->val, upper);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        int taken = 0;
        TreeNode* root = constructBST(taken, preorder.size(), preorder, INT_MIN, INT_MAX);
        return root;
    }
};