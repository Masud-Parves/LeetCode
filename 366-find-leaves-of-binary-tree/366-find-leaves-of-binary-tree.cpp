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
    int markHeightNode(TreeNode* node, vector<vector<int>>& result){
        if(node == NULL) return -1;
        
        int lh = markHeightNode(node->left, result);
        int rh = markHeightNode(node->right, result);
        
        int height = 1 + max(lh, rh);
        
        if(result.size() == height){
            result.push_back({});
        }
        
        result[height].push_back(node->val);
        
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        
        markHeightNode(root, result);
        
        return result;
    }
};