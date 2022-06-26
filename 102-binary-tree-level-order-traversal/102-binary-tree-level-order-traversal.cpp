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
    void helper(TreeNode* node, int level, vector<vector<int>>& order){
        if(node == NULL) {
            return;
        }
        if(order.size() == level){
            order.push_back({});
        }
        
        order[level].push_back(node->val);
        helper(node->left, level+1, order);
        helper(node->right, level+1, order);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>order;
        if(root == NULL) {
            return order;
        }
        helper(root, 0, order);
        return order;
    }
};