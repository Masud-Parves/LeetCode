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
    int helper(TreeNode* currNode, unordered_map<int, int>& ret, int& maxCount){
        if(currNode == NULL) return 0;
        
        int left = helper(currNode->left, ret, maxCount);
        int right = helper(currNode->right, ret, maxCount);
        
        int total = currNode->val + left + right;
        ret[total]++;
        maxCount = max(maxCount, ret[total]);
        return total;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        unordered_map<int, int> ret;
        int maxCount = 0;
        helper(root, ret, maxCount);
        for(auto m : ret){
            if(maxCount == m.second){
                result.push_back(m.first);
            }
        }
        return result;
    }
};