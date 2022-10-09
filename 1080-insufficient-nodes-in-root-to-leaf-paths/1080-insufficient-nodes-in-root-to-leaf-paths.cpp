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
    TreeNode* dfsTraversal(TreeNode* node, int& limit, int sum){
        if(node == NULL){
            return NULL;
        }
        
        sum+= node->val;
        if(node->left == NULL && node->right == NULL){
            if(sum<limit) return NULL;
            return node;
        }
        
        TreeNode* leftNode = dfsTraversal(node->left, limit, sum);
        TreeNode* rightNode = dfsTraversal(node->right, limit, sum);
        if(leftNode == NULL && rightNode == NULL){
            return NULL;
        }
        node->left = leftNode;
        node->right = rightNode;
        

        return node;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL){
            return NULL;
        }
        int sum = 0;
        TreeNode* newRoot = dfsTraversal(root, limit, sum);
        return newRoot;
    }
};