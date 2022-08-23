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
    bool isSameTree(TreeNode* currRoot, TreeNode* subRoot){
        if(currRoot == NULL && subRoot == NULL){
            return true;
        }
        if(currRoot == NULL || subRoot == NULL || currRoot->val != subRoot->val){
            return false;
        }
        
        return isSameTree(currRoot->left, subRoot->left) && isSameTree(currRoot->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* currRoot, TreeNode* subRoot) {
        if(currRoot == NULL) return false;
        if(subRoot == NULL) return true;
        
        if(isSameTree(currRoot, subRoot)) return true;
        
        return isSubtree(currRoot->left, subRoot) || isSubtree(currRoot->right, subRoot);
    }
};