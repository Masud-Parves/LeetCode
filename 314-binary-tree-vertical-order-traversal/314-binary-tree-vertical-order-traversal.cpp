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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        
        map<int, vector<int>> nodes;
        queue<pair<TreeNode* , int>> todo;
        todo.push({root, 0});
        
        while(!todo.empty()){
            auto uNode = todo.front();
            todo.pop();
            
            TreeNode* node = uNode.first;
            int row = uNode.second;
            
            nodes[row].push_back(node->val);
            
            if(node->left != NULL){
                todo.push({node->left, row-1});
            }
            if(node->right != NULL){
                todo.push({node->right, row+1});
            }
        }
        
        for(auto& node : nodes){
            vector<int>level;
            level.insert(level.begin(),node.second.begin(), node.second.end());
            result.push_back(level);
        }
        return result;
    }
};