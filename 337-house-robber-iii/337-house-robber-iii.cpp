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
    pair<int, int> treeTraversal(TreeNode* node){
        if(node == NULL){
            return {0, 0};
        }
        
        pair<int, int> left = treeTraversal(node->left);
        pair<int, int> right = treeTraversal(node->right);
        int withRoot = node->val + left.second + right.second;
        int withoutRoot = max(left.first, left.second) + max(right.first, right.second);
        return {withRoot, withoutRoot};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> result = treeTraversal(root);
        return max(result.first, result.second);
    }
};