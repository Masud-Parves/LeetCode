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
    void dfsTraversal(TreeNode* node, vector<string>& result, string path){
        if(node == NULL) {
            return;
        }
        
        if(node->left == NULL && node->right == NULL){
            path += (to_string(node->val));
            result.push_back(path);
            return;
        }
        
        path += to_string(node->val) + "->";
        dfsTraversal(node->left, result, path);
        dfsTraversal(node->right, result, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(root == NULL){
            return result;
        }
        string p;
        dfsTraversal(root, result, p);
        return result;
    }
};