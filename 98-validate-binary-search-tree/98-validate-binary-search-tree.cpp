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
    bool isValid(TreeNode* node, long long minValue, long long maxValue){
        if(node == NULL){
            return true;
        }
        
        if(node->val<=minValue or node->val>=maxValue) return false;
        return isValid(node->left, minValue, node->val) && isValid(node->right, node->val, maxValue);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};