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
    int dfs(TreeNode* node, int& noOfCamera){
        if(node == NULL){
            return 1;
        }
        
        int left = dfs(node->left, noOfCamera);
        int right = dfs(node->right, noOfCamera);
        
        if(left == 0 || right == 0) {
            noOfCamera++;
            return 2;
        } else if(left == 2 || right == 2) {                      
            return 1;
        } else {
            return 0;
        }
        return -1; // for invalid case
    }
public:
    int minCameraCover(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int noOfCamera = 0;
        return dfs(root, noOfCamera) == 0? (noOfCamera +1) : noOfCamera;
    }
};