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
    
    TreeNode* buildBalancedBST(int start, int end, vector<int>& inorder){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildBalancedBST(start, mid-1, inorder);
        root->right = buildBalancedBST(mid+1, end, inorder);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        vector<int>inorder;
        inorderTraversal(root, inorder);
        root = buildBalancedBST(0, inorder.size()-1, inorder);
        return root;
    }
};