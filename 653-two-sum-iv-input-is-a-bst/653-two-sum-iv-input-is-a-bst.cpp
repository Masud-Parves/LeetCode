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
    unordered_set<int> cache;
public:
    bool findTarget(TreeNode* root, int target) {
        if(root == NULL) {
            return false;
        }
        
        if(cache.find(target-root->val) != cache.end()){
            return true;
        }
        cache.insert(root->val);
        
        return findTarget(root->left, target) ||
                findTarget(root->right, target); 
    }
};