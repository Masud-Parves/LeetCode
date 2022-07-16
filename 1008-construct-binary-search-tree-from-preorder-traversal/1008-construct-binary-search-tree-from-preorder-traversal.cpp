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
    TreeNode* constructBST(int& take, int L, int R, vector<int>& inorder, vector<int>& preorder, unordered_map<int, int>& seen){
        if(L>R) return NULL;
        
        int nodeVal = preorder[take++];
        int pos = seen[nodeVal];
        TreeNode* root = new TreeNode(nodeVal);

        root->left = constructBST(take, L, pos-1, inorder, preorder, seen);
        root->right = constructBST(take, pos+1, R, inorder, preorder, seen);
        
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int>inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        
        unordered_map<int, int> seen;
        for(int i=0; i<inorder.size(); i++){
            seen[inorder[i]] = i;
        }
        int take = 0;
        TreeNode* root = constructBST(take, 0, n-1, inorder, preorder, seen);
        return root;
    }
};