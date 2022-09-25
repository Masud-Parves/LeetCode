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
    void helper(TreeNode* currNode, unordered_map<int, int>& seen, int& maxCount){
        if(currNode == NULL) {
            return;
        }
        
        helper(currNode->left, seen, maxCount);
        seen[currNode->val]++;
        maxCount = max(maxCount, seen[currNode->val]);
        helper(currNode->right, seen, maxCount);
        
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        unordered_map<int, int> seen;
        int maxCount = 0;
        helper(root, seen, maxCount);
        for(auto& element : seen){
            if(element.second == maxCount){
                result.push_back(element.first);
            }
        }
        return result;
    }
};