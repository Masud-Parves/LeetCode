class Solution {
private:
    void preorderTraversal(TreeNode* node, int row, int col, map<int, map<int, multiset<int>>>& nodes){
        if(node == NULL){
            return;
        }
        
        nodes[row][col].insert(node->val);
        preorderTraversal(node->left, row-1, col+1, nodes);
        preorderTraversal(node->right, row+1, col+1, nodes);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        map<int, map<int, multiset<int>>> nodes; // row, col, val
        
        preorderTraversal(root, 0, 0, nodes);
        
        for(auto& node : nodes){
            vector<int>level;
            for(auto ele : node.second){
                level.insert(level.end(), ele.second.begin(), ele.second.end());
            }
            result.push_back(level);
        }
        return result;
    }
};