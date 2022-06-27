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
    int depthOfBT(TreeNode* node){
        if(node == NULL) {
            return 0;
        }

        int leftDepth = depthOfBT(node->left);
        int rightDepth = depthOfBT(node->right);

        return 1 + max(leftDepth, rightDepth);
        
    }
    
    bool isTreeBalanced(TreeNode* node){
        int leftHeight = depthOfBT(node->left);
        int rightHeight = depthOfBT(node->right);
        return (abs(leftHeight - rightHeight) <= 1);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        queue<TreeNode*>Q;
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
            for(int i=0; i<size; i++){
                TreeNode* currNode = Q.front();
                Q.pop();
                
                if(isTreeBalanced(currNode) == false){
                    return false;
                }
                
                if(currNode->left != NULL) {
                    Q.push(currNode->left);
                }
                if(currNode->right != NULL){
                    Q.push(currNode->right);
                }
            }
        }
        return true;
    }
};
