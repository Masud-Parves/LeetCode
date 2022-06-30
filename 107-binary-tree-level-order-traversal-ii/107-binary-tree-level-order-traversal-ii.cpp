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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> todo;
        todo.push(root);
        
        while(!todo.empty()){
            int size = todo.size();
            vector<int>level;
            
            for(int i=0; i<size; i++){
                TreeNode* node = todo.front();
                todo.pop();
                
                level.push_back(node->val);
                if(node->left != NULL) {
                    todo.push(node->left);
                }
                if(node->right != NULL){
                    todo.push(node->right);
                }
            }
            result.insert(result.begin(), level);
        }
        return result;
    }
};