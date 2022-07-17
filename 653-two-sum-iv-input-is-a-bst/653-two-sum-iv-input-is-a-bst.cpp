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
    bool dfsTraversal(TreeNode* node, int target, unordered_set<int>& seen){
        if(node == NULL){
            return false;
        }
        if(seen.find(target-node->val) != seen.end()){
            return true;
        }
        seen.insert(node->val);
        return dfsTraversal(node->left, target, seen) || dfsTraversal(node->right, target, seen);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfsTraversal(root, k, seen);
    }
};