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
    int findLeftHeight(TreeNode* node){
        if(node == NULL) return 0;
        return 1 + findLeftHeight(node->left);
    }
    int findRightHeight(TreeNode* node){
        if(node == NULL) return 0;
        return 1 + findRightHeight(node->right);
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int dl = findLeftHeight(root);
        int dr = findRightHeight(root);
        
        if(dl == dr) {
            return pow(2, dl)-1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};