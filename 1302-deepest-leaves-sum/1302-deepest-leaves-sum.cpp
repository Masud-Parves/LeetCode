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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<TreeNode*>Q;
        Q.push(root);
        int sum = 0;
        while(!Q.empty()){
            int size = Q.size();
            sum = 0;
            while(size--){
                TreeNode* node = Q.front();
                Q.pop();
                
                sum += node->val;
                
                if(node->left != NULL){
                    Q.push(node->left);
                }
                
                if(node->right != NULL){
                    Q.push(node->right);
                }
                
            }
        }
        return sum;
    }
};