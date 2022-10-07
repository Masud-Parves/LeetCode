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
    bool isEvenOddTree(TreeNode* root) {
        if(root== NULL) return false;
        queue<TreeNode*> todo;
        todo.push(root);
        int level = 0;
        while(!todo.empty()){
            int size = todo.size();
            int prevIn = INT_MIN, prevDe = INT_MAX;;
            for(int i=0; i<size; i++){
                TreeNode* currNode = todo.front();
                int currVal = currNode->val;
                todo.pop();
                if(level%2==0 && currVal%2 == 0) return false;
                if(level%2==1 && currVal%2 == 1) return false;
                
                if(level%2==0){
                    // should be increasing
                    
                    if(prevIn>=currVal) return false;
                    prevIn = currVal;
                } else {
                    // should be decresing
                    if(prevDe<=currVal) return false;
                    prevDe = currVal;
                }
                if(currNode->left != NULL) todo.push(currNode->left);
                if(currNode->right != NULL) todo.push(currNode->right);
            }
            level++;
        }
        return true;
    }
};