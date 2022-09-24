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
    void getAllPaths(TreeNode* node, int target, vector<int> path, vector<vector<int>>& result){
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL){
            if(target == node->val){
                path.push_back(node->val);
                result.push_back(path);
            }
            
            return;
        }
        
        path.push_back(node->val);
        getAllPaths(node->left, target-node->val, path, result);
        getAllPaths(node->right, target-node->val, path, result);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        vector<int>path;
        getAllPaths(root, target, path, result);
        return result;
    }
};