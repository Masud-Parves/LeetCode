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
    int markHeightNode(TreeNode* node, vector<pair<int, int>>& pairs){
        if(node == NULL) return -1;
        
        int lh = markHeightNode(node->left, pairs);
        int rh = markHeightNode(node->right, pairs);
        
        int height = 1 + max(lh, rh);
        pairs.push_back({height, node->val});
        
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        if(root == NULL) {
            return {{}};
        }
        
        vector<pair<int, int>> pairs;
        int height = markHeightNode(root, pairs);
        
        vector<vector<int>> result(height+1);
        for(auto& pair : pairs){
            result[pair.first].push_back(pair.second);
        }
        return result;
    }
};