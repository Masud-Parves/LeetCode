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
    void preorderTraversal(TreeNode* node, int level, bool leftToRight, vector<vector<int>>& result){
        if(node == NULL) return;
        
        if(result.size() == level) {
            result.push_back(vector<int>(0));
        }
        
        if(leftToRight == true) {
            result[level].push_back(node->val);
        } else {
            result[level].insert(result[level].begin(), node->val);
        }
        
        preorderTraversal(node->left, level+1, !leftToRight, result);
        preorderTraversal(node->right, level+1, !leftToRight, result);
        
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) {
            return result;
        }
        preorderTraversal(root, 0, true, result);
        return result;
    }
};