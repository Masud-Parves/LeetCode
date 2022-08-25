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
    void countGoodNodes(TreeNode* node, int tillMax, int& result){
        if(node == NULL) return;
        
        if(node->val >= tillMax){
            result++;
            tillMax = node->val;
        }
        
        countGoodNodes(node->left, tillMax, result);
        countGoodNodes(node->right, tillMax, result);
    }
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        countGoodNodes(root, root->val, result);
        return result;
    }
};