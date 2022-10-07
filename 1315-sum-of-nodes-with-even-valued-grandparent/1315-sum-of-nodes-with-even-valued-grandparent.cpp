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
    int isEvenValuedGrandparent(TreeNode* node){
        if(node == NULL) return 0;
        int bothSum = 0;
        if(node->left != NULL) bothSum += node->left->val;
        if(node->right != NULL) bothSum += node->right->val;
        return bothSum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        queue<TreeNode*> todo;
        todo.push(root);
        int total = 0;
        while(!todo.empty()){
            TreeNode* currNode = todo.front();
            todo.pop();
            int currVal = currNode->val;
            if(currVal%2 == 0){
                total += isEvenValuedGrandparent(currNode->left);
                total += isEvenValuedGrandparent(currNode->right);
            }
            if(currNode->left != NULL) todo.push(currNode->left);
            if(currNode->right != NULL) todo.push(currNode->right);
        }
        return total;
    }
};