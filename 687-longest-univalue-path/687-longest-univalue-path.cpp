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
    int helper(TreeNode* currNode, int& ans){
        if(currNode == NULL){
            return 0;
        }
        
        int left = helper(currNode->left, ans);
        int right= helper(currNode->right, ans);
        int leftArrow = 0, rightArrow = 0;
        if(currNode->left != NULL && currNode->left->val == currNode->val){
            leftArrow += left+1;
        }
        if(currNode->right != NULL && currNode->right->val == currNode->val){
            rightArrow += right+1;
        }
        
        ans = max(ans, leftArrow+rightArrow);
        
        return max(leftArrow, rightArrow);
        
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};