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
    
    pair<int, int> dfs(TreeNode* node){
        if(node == NULL){
                // sum, count
            return {0, 0};
        }
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        pair<int, int> currNode = {left.first+right.first+node->val, left.second+right.second+1};
        
        return cache[node] = currNode;
    }
    
    void preorderTraversal(TreeNode* node, int& answer){
        if(node == NULL) {
            return;
        }
        if(node->left == NULL && node->right == NULL){
            answer++;
            return;
        }
        
        int sum = cache[node].first, child = cache[node].second;
        int avg = sum/child;
        if(avg == node->val){
            answer++;
        }
        
        preorderTraversal(node->left, answer);
        preorderTraversal(node->right, answer);
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        int result = 0;
        preorderTraversal(root, result);
        return result;
    }
};