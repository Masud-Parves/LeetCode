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
    int calculateMaxSum(TreeNode* node, int& result){
        if(node == NULL){
            return 0;
        }
        
        int left = calculateMaxSum(node->left, result);
        int right = calculateMaxSum(node->right, result);
        
        int single_path = max(max(left, right)+node->val, node->val);
        int both_path = max(single_path, left+right+node->val);

        result = max(result, both_path);
        return single_path;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int result = INT_MIN;
        calculateMaxSum(root, result);
        return result;
    }
};