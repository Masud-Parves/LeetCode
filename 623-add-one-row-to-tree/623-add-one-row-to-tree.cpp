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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int level = 1;
        queue<TreeNode*> todo;
        todo.push(root);
        
        while(!todo.empty() && depth>0){
            int size = todo.size();
            depth--;
            for(int i=0; i<size; i++){
                TreeNode* currNode = todo.front();
                todo.pop();
                if(depth == 1){

                    TreeNode* newNode = new TreeNode(val);
                    if(currNode->left != NULL){
                        TreeNode* left = currNode->left;
                        currNode->left = newNode;
                        newNode->left = left;
                    } else currNode->left = newNode;
                    
                    TreeNode* newNode1 = new TreeNode(val);
                    if(currNode->right != NULL){
                        TreeNode* right = currNode->right;
                        currNode->right = newNode1;
                        newNode1->right = right;
                    } else currNode->right = newNode1;
                    
                } else {
                    if(currNode->left != NULL){
                        todo.push(currNode->left);
                    }
                    if(currNode->right != NULL){
                        todo.push(currNode->right);
                    }
                }
            }
            level++;
            
        }
        return root;
    }
};