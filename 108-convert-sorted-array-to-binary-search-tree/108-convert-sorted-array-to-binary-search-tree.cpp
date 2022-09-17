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
    TreeNode* generateBST(int low, int high, vector<int>& nums){
        if(low>high){
            return NULL;
        }
        
        int currIdx = low + (high-low)/2;
        TreeNode* root = new TreeNode(nums[currIdx]);
        root->left = generateBST(low, currIdx-1, nums);
        root->right = generateBST(currIdx+1, high, nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return NULL;
        }
        
        return generateBST(0, n-1, nums);
    }
};