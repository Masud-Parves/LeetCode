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
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        int result;
        queue<TreeNode*>todo;
        todo.push(root);
        
        while(!todo.empty()){
            int size = todo.size();
            
            for(int i=0; i<size; i++){
                TreeNode* node = todo.front();
                todo.pop();
                if(i==0){
                    result = node->val;
                }
                if(node->left != NULL) {
                    todo.push(node->left);
                }
                
                if(node->right != NULL) {
                    todo.push(node->right);
                }
            }
        }
        return result;
        
    }
};