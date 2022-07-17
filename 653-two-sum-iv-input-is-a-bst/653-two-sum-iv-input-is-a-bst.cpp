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
    void inorderTraversal(TreeNode* node, vector<int>& inorder){
        if(node == NULL){
            return;
        }
        inorderTraversal(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraversal(node->right, inorder);
    }
public:
    bool findTarget(TreeNode* root, int target) {
        vector<int>inorder;
        inorderTraversal(root, inorder);
        int left = 0, right = inorder.size()-1;
        while(left<right){
            if(inorder[left] + inorder[right] == target){
                return true;
            } else if(inorder[left] + inorder[right] < target){
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};