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
    
    TreeNode* buildBinaryTree(int start, int end, int& take, vector<int>& preorder, unordered_map<int, int>& index){
        if(start > end) {
            return NULL;
        }
        
        TreeNode* node = new TreeNode(preorder[take++]);
        int idx = index[node->val];
        node->left = buildBinaryTree(start, idx-1, take, preorder, index);
        node->right = buildBinaryTree(idx+1, end, take, preorder, index);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) {
            return NULL;
        }
        
        // node value , idx
        unordered_map<int, int> index;
        for(int i=0; i<inorder.size(); i++){
            index[inorder[i]] = i;
        }
        int take = 0;
        TreeNode* root = buildBinaryTree(0, inorder.size()-1, take, preorder, index);
        return root;
    }
};