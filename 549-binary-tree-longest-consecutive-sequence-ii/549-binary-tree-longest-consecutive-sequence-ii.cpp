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
    pair<int, int> helper(TreeNode* node, int& result, int p=0){
        if(node == NULL){
            return {0, 0};
        }
        
        auto left = helper(node->left, result, node->val);
        auto right = helper(node->right, result, node->val);
        
        result = max(result, max(left.first+1+right.second, left.second+1+right.first));

        if(p-node->val == 1){
            return {0, max(left.second, right.second)+1};
        }
        if(p-node->val == -1) {
            return {max(left.first, right.first)+1, 0};
        }
        return {0, 0};
    }
public:
    int longestConsecutive(TreeNode* root) {
        int result = 0;
        helper(root, result);
        return result;
    }
};