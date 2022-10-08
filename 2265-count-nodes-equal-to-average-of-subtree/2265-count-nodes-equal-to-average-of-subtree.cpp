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
    unordered_map<TreeNode*, pair<int, int>> cache;
    
    pair<int, int> dfs(TreeNode* node, int& answer){
        if(node == NULL){
                // sum, count
            return {0, 0};
        }
        
        if(node->left == NULL && node->right == NULL){
            answer++;
            return {node->val, 1};
        }
        
        auto left = dfs(node->left, answer);
        auto right = dfs(node->right, answer);
        
        int sum = left.first+right.first+node->val, count = left.second+right.second+1, avg=0;
        avg = sum/count;
        if(avg == node->val){
            answer++;
        }
        
        return {left.first+right.first+node->val, count = left.second+right.second+1};
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int result = 0;
        dfs(root, result);
        return result;
    }
};