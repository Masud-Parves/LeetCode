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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>result;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
            double ret = 0.0;
            for(int i=0; i<size; i++){
                TreeNode* node = Q.front();
                Q.pop();
                
                ret += node->val;
                if(node->left != NULL){
                    Q.push(node->left);
                }
                if(node->right != NULL){
                    Q.push(node->right);
                }
            }
            result.push_back(ret/size);
        }
        return result;
    }
};