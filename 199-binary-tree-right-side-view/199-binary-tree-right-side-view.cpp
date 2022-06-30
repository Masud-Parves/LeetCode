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
    void preorderTraversal(TreeNode* node, int level, map<int, int>& cache){
        if(node == NULL) {
            return;
        }
        
        if(cache.count(level) == 0){
            cache[level] = node->val;
        }
        preorderTraversal(node->right, level+1, cache);
        preorderTraversal(node->left, level+1, cache);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        
        map<int,int>cache; // level, val
        
        preorderTraversal(root, 0, cache);
        
        for(auto x:cache){
            ans.push_back(x.second);
        }
        return ans;
    }
};