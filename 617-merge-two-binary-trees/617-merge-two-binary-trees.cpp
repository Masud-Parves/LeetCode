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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }
        
        int rootVal1 = root1 != NULL ? root1->val : 0;
        int rootVal2 = root2 != NULL ? root2->val : 0;
        TreeNode* root = new TreeNode(rootVal1 + rootVal2);
        TreeNode* left1 = root1 != NULL ? root1->left : NULL;
        TreeNode* left2 = root2 != NULL ? root2->left : NULL;
        
        TreeNode* right1 = root1 != NULL ? root1->right : NULL;
        TreeNode* right2 = root2 != NULL ? root2->right : NULL;
        
        root->left = mergeTrees(left1, left2);
        root->right = mergeTrees(right1, right2);
        return root;
    }
};