/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        
        queue<TreeNode*> todo;
        todo.push(root);
        
        while(!todo.empty()){
            TreeNode* node = todo.front();
            todo.pop();
            
            if(node->left != NULL){
                parent[node->left] = node;
                todo.push(node->left);
            }
            if(node->right != NULL){
                parent[node->right] = node;
                todo.push(node->right);
            }
        }
    }
    
    void getKDistanceNode(TreeNode* root, unordered_map<TreeNode*,
                          TreeNode*>& parent, int k, vector<int>& result){
        
        queue<TreeNode*> todo;
        unordered_map<TreeNode*, int> visited;
        todo.push(root);
        //int level = 0;
        while(!todo.empty()){
            int size = todo.size();
            
            for(int i=0; i<size ; i++){
                TreeNode* node = todo.front();
                todo.pop();
                
                if(0 == k) result.push_back(node->val);
                
                if(node->left != NULL && !visited.count(node->left)){
                    visited[node->left] = 1;
                    todo.push(node->left);
                }
                if(node->right != NULL && !visited.count(node->right)){
                    visited[node->right] = 1;
                    todo.push(node->right);
                }
                if(parent[node] != NULL && !visited.count(node)) {
                    visited[node] = 1;
                    todo.push(parent[node]);
                }
            }
            k--;
        }
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        
        unordered_map<TreeNode*, TreeNode*>parent;
        makeParent(root, parent);
        getKDistanceNode(target, parent, k, result);
        
        return result;
    }
};