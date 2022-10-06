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
    void levelOrderTraversal(TreeNode* root, TreeNode* &left, TreeNode* &right){
        queue<TreeNode*> todo;
        todo.push(root);
        
        while(!todo.empty()){
            int size = todo.size();
            
            for(int i=0; i<size; i++){
                TreeNode* currNode = todo.front();
                todo.pop();
                if(i==0) left = currNode;
                if(i==size-1) right = currNode;
                
                if(currNode->left != NULL) todo.push(currNode->left);
                if(currNode->right != NULL) todo.push(currNode->right);
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* left, TreeNode* right){
        if(node == NULL){
            return NULL;
        }
        if(node == left || node==right){
            return node;
        }
        TreeNode* leftNode = lowestCommonAncestor(node->left, left, right);
        TreeNode* rightNode = lowestCommonAncestor(node->right, left, right);
        
        if(leftNode && rightNode){
            return node;
        } else if(leftNode) return leftNode;
        return rightNode;
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode *left, *right;
        levelOrderTraversal(root, left, right);
        TreeNode* lca = lowestCommonAncestor(root, left, right);
        return lca;
    }
};