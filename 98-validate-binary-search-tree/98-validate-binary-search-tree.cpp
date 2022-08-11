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
    bool isValid(TreeNode* node, long long minVal, long long maxVal){
        if(node == NULL) return true;
        
        if(node->val>=maxVal or node->val<=minVal) return false;
        return isValid(node->left, minVal, node->val) && isValid(node->right, node->val, maxVal);
        
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};