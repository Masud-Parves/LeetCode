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
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int depth = 0;
        queue<TreeNode*>Q;
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
            depth++;
            for(int i=0; i<size; i++){
                TreeNode* node = Q.front();
                Q.pop();
                if(node->left != NULL) {
                    Q.push(node->left);
                }
                if(node->right != NULL) {
                    Q.push(node->right);
                }
            }
        }
        
        return depth;
    }
};