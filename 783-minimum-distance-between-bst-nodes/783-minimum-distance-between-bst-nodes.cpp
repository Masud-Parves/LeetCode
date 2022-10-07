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
    void inorderTraversal(TreeNode* node, vector<int>& nums){
        if(node == NULL) return;
        inorderTraversal(node->left, nums);
        nums.push_back(node->val);
        inorderTraversal(node->right, nums);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        inorderTraversal(root, nums);
        int ret = INT_MAX;
        for(int i=1; i<nums.size(); i++){
            ret = min(ret, nums[i]-nums[i-1]);
        }
        return ret;
    }
};