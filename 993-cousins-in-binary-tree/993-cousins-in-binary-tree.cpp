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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL){
            return false;
        }
        queue<pair<TreeNode*, int>> todo;
        todo.push({root, -1});
        
        while(!todo.empty()){
            int size = todo.size();
        
            int match = 0;
            int xp = -1, yp = -1;
            for(int i=0; i<size; i++){
                TreeNode* currNode = todo.front().first;
                int parent = todo.front().second;
                todo.pop();
                
                if(currNode->val == x){
                    xp = parent;
                    match+=1;
                } else if(currNode->val == y){
                    yp = parent;
                    match+=1;
                }
                
                if(currNode->left != NULL){
                    todo.push({currNode->left, currNode->val});
                }
                if(currNode->right != NULL){
                    todo.push({currNode->right, currNode->val});
                }
            }
            if(match == 2 && xp != yp) return true;
        }
        return false;
    }
};