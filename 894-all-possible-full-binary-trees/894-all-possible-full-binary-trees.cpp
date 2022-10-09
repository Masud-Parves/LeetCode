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
    vector<TreeNode*> helper(int n){
        vector<TreeNode*> result;
        if(n==1){
            TreeNode* baseRoot = new TreeNode(0);
            result.push_back(baseRoot);
            return result;
        } else if(n%2==1){
            for(int r=1; r<=n; r++){
                vector<TreeNode*> left = helper(r-1);
                vector<TreeNode*> right = helper(n-r);
                for(auto& leftNode : left){
                    for(auto& rightNode : right){
                        TreeNode* root = new TreeNode(0);
                        root->left = leftNode;
                        root->right = rightNode;
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result = helper(n);
        return result;
    }
};