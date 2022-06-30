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
    void preorderTraversal(TreeNode* node, int level, vector<vector<int>>& result){
        if(node == NULL){
            return;
        }
        
        if(result.size() == level){
            result.push_back(vector<int>());
        }
        
        result[level].push_back(node->val);
        preorderTraversal(node->left, level+1, result);
        preorderTraversal(node->right, level+1, result);
        
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        preorderTraversal(root, 0, result);
        reverse(result.begin(), result.end());
        return result;
    }
};