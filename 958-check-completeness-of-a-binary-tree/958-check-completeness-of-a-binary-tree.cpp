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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        queue<TreeNode*> todo;
        todo.push(root);
        bool isCheck = false;
        while(!todo.empty()){
            int size = todo.size();
 
            for(int i=0; i<size; i++){
                TreeNode* currNode = todo.front();
                todo.pop();

                if(isCheck == true && (currNode->left != NULL || currNode->right != NULL)){
                    //cout << currNode->left->val << " " << currNode->right->val << endl;
                    return false;
                }
                
                
                if(currNode->left == NULL){
                    isCheck = true;
                    if(currNode->right != NULL) return false;
                } 
                if(currNode->right == NULL){
                    isCheck = true;
                }
                
                
                if(currNode->left != NULL){
                    todo.push(currNode->left);
                }
                if(currNode->right != NULL){
                    todo.push(currNode->right);
                }
            }

        }
        return true;
    }
};