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
    vector<TreeNode*> helper(int n, unordered_map<int, vector<TreeNode*>>& cache){
        vector<TreeNode*> result;
        if(n==1){
            TreeNode* baseRoot = new TreeNode(0);
            result.push_back(baseRoot);
            return result;
        }
        
        if(cache.find(n) != cache.end()){
            return cache[n];
        }
        
        if(n%2==1){
            for(int r=1; r<=n; r++){
                vector<TreeNode*> left = helper(r-1, cache);
                vector<TreeNode*> right = helper(n-r, cache);
                
                for(auto& leftFBT : left){
                    for(auto& rightFBT : right){
                        TreeNode* root = new TreeNode(0);
                        root->left = leftFBT;
                        root->right = rightFBT;
                        result.push_back(root);
                    }
                }
            }
        }
        
        return cache[n] = result;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> cache;
        vector<TreeNode*> result = helper(n, cache);
        return result;
    }
};