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
    void preorderTraversal(TreeNode* node, int row, int col, map<int,map<int,vector<int>>>& nodes){
        if(node == NULL) {
            return;
        }
        
        nodes[row][col].push_back(node->val);
        preorderTraversal(node->left, row-1, col+1, nodes);
        preorderTraversal(node->right, row+1, col+1, nodes);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        
        map<int,map<int,vector<int>>> nodes;
        preorderTraversal(root, 0,  0, nodes);
            
        for(auto& node : nodes){
            vector<int> level;
            for(auto nd : node.second){
                for(auto& ele : nd.second){
                     level.push_back(ele);
                }
            }
           result.push_back(level);
        }
        return result;
    }
};