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
    bool dfsTraversal(TreeNode* node, int targetSum){
        if(node == NULL) return false;
        if(node->left==NULL && node->right==NULL){
            return targetSum == node->val;
        }
        
        bool leftSub = dfsTraversal(node->left, targetSum-node->val);
        if(leftSub) return true;
        bool rightSub = dfsTraversal(node->right, targetSum-node->val);
        if(rightSub) return true;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfsTraversal(root, targetSum);
    }
};