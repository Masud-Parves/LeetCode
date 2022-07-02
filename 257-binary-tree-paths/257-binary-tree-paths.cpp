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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        if(root == NULL){
            return result;
        }
        queue<pair<TreeNode*, string>> todo;
        todo.push({root, to_string(root->val)});
        
        while(!todo.empty()){
            auto current = todo.front();
            todo.pop();
            TreeNode* node = current.first;
            string path = current.second;
            
            if(node->left == NULL && node->right == NULL) {
                result.push_back(path);
            } else {
                if(node->left != NULL) {
                    todo.push({node->left, path+"->"+to_string(node->left->val)});
                }
                if(node->right != NULL) {
                    todo.push({node->right, path+"->"+to_string(node->right->val)});
                }
            }
            
        }
        return result;
    }
};