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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int maxSum = INT_MIN, maxSumIdx = 1, level = 1;
        queue<TreeNode*> todo;
        todo.push(root);
        
        while(!todo.empty()){
            int size = todo.size();
            
            int currLevelSum = 0;
            for(int i=0; i<size; i++){
                TreeNode* currNode = todo.front();
                todo.pop();
                
                currLevelSum += currNode->val;
                if(currNode->left != NULL){
                    todo.push(currNode->left);
                }
                if(currNode->right != NULL){
                    todo.push(currNode->right);
                }
            }
            
            if(maxSum<currLevelSum){
                maxSum = currLevelSum;
                maxSumIdx = level;
            }
            level++;
            
        }
        return maxSumIdx;
    }
};