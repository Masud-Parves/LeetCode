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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        map<int, map<int, multiset<int>>> mp; // row, col, val
        
        queue<pair<TreeNode*, pair<int, int>>> Q;
        Q.push({root, {0, 0}});
        
        while(!Q.empty()){
            auto uNode = Q.front();
            Q.pop();
            TreeNode* node = uNode.first;
            int row = uNode.second.first;
            int col = uNode.second.second;
            
            mp[row][col].insert(node->val);
            if(node->left != NULL) {
                Q.push({node->left,{row-1, col+1}});
            }
            if(node->right != NULL) {
                Q.push({node->right,{row+1, col+1}});
            }
        }
        
        for(auto& m : mp){
            vector<int>level;
            for(auto ele : m.second){
                level.insert(level.end(), ele.second.begin(), ele.second.end());
            }
            result.push_back(level);
        }
        return result;
    }
};