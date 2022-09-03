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
    TreeNode* buildTree(int L, int R, vector<int>& nums){
        
        if(L>R) return NULL;
        int maxVal = INT_MIN, idx = -1;
        for(int i=L; i<=R; i++){
            if(maxVal<nums[i]){
                idx = i;
                maxVal = nums[i];
            }
        }
        
        TreeNode* root = new TreeNode(maxVal);
        root->left = buildTree(L, idx-1, nums);
        root->right = buildTree(idx+1, R, nums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        
        return buildTree(0, nums.size()-1, nums);
    }
};