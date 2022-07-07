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
    void getLeafNode(TreeNode* node, vector<int>& leafNode){
        if(node == NULL) {
            return;
        }
        if(node->left == NULL && node->right == NULL){
            leafNode.push_back(node->val);
            return;
        }
        getLeafNode(node->left, leafNode);
        getLeafNode(node->right, leafNode);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) {
            return true;
        }
        if(root1 == NULL || root2 == NULL) {
            return false;
        }
        vector<int>leafA, leafB;
        getLeafNode(root1, leafA);
        getLeafNode(root2, leafB);
        
        if(leafA.size()!=leafB.size()) {
            return false;
        }
        
        for(int i=0; i<leafA.size(); i++){
            if(leafA[i] != leafB[i]){
                return false;
            }
        }
        return true;
    }
};