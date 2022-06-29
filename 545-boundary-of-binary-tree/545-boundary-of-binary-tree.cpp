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
    bool isLeaf(TreeNode* node){
        return (node->left == NULL && node->right == NULL);
    }
    
    bool isRootNode(int flag){
        return (flag == 0);
    }
    
    bool isLeftBoundary(int flag){
        return (flag == 1);
    }
    
    bool isRightBoundary(int flag){
        return (flag == 2);
    }
    
    int leftChildFlag(TreeNode* node, int flag){
        if(isLeftBoundary(flag) || isRootNode(flag)) {
            return 1;
        } else if(isRightBoundary(flag) && node->right == NULL) {
            return 2;
        }
        return 3;
    }
    
    int rightChildFlag(TreeNode* node, int flag){
        if(isRightBoundary(flag) || isRootNode(flag)) {
            return 2;
        } else if(isLeftBoundary(flag) && node->left == NULL) {
            return 1;
        }
        return 3;
    }
    
    void preorderTraveral(TreeNode* node, vector<int>& leftBoundary, vector<int>&rightBoundary, vector<int>& leafBoundary, int flag){
        if(node == NULL) {
            return;
        }
        
        if(isLeftBoundary(flag) || isRootNode(flag)) {
            leftBoundary.push_back(node->val);
        } else if(isRightBoundary(flag) || isRootNode(flag)) {
            rightBoundary.insert(rightBoundary.begin(), node->val);
        } else if(isLeaf(node)) {
            leafBoundary.push_back(node->val);
        }
        
        preorderTraveral(node->left, leftBoundary, rightBoundary, leafBoundary, leftChildFlag(node, flag));
        preorderTraveral(node->right, leftBoundary, rightBoundary, leafBoundary, rightChildFlag(node, flag));
        
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        
        vector<int> leftBoundary, rightBoundary, leafBoundary;
        preorderTraveral(root, leftBoundary, rightBoundary, leafBoundary, 0);
        
        for(auto& leafNode : leafBoundary) {
            leftBoundary.push_back(leafNode);
        }
        for(auto& rightNode : rightBoundary) {
            leftBoundary.push_back(rightNode);
        }
        return leftBoundary;
    }
};