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
    int dfs(TreeNode* node, stack<int>& seen){
        if(node == NULL){
            return 0;
        }
        
        int currSum = dfs(node->left, seen) + dfs(node->right, seen) + node->val;
        seen.push(currSum);
        return currSum;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        if(root == NULL){
            return false;
        }
        stack<int> seen;
        
        int total = dfs(root, seen);
        if(total&1){
            return false;
        }
        seen.pop();
        while(!seen.empty()){
            
            if(seen.top() == total/2) return true;
            seen.pop();
        }
        return false;
    }
};