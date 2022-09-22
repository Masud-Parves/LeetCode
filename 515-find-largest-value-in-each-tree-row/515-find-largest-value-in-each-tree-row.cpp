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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> todo;
        todo.push(root);
        
        while(!todo.empty()){
            int size = todo.size();
            
            int maxVal = INT_MIN;
            for(int i=0; i<size; i++){
                TreeNode* node = todo.front();
                todo.pop();
                
                maxVal = max(maxVal, node->val);
                if(node->left != NULL){
                    todo.push(node->left);
                }
                if(node->right != NULL){
                    todo.push(node->right);
                }
            }
            result.push_back(maxVal);
        }
        return result;
    }
};