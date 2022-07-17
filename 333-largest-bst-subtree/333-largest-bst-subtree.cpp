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
class NodeInfo{
public:
    int size, maxVal, minVal;
    NodeInfo(int totalSum, int maxValue, int minValue){
        size = totalSum;
        maxVal = maxValue;
        minVal = minValue;
    }
};

class Solution {
private:
    /// cnt, -->maxVal, minVal
    NodeInfo postOrderTraversal(TreeNode* node){
        if(node == NULL){
            return NodeInfo(0, INT_MIN, INT_MAX);
        }
        NodeInfo left = postOrderTraversal(node->left);
        NodeInfo right = postOrderTraversal(node->right);
        
        if(left.maxVal< node->val && node->val < right.minVal){
            return NodeInfo(left.size+right.size+1, max(right.maxVal, node->val), min(left.minVal, node->val));
        }
        return NodeInfo(max(left.size, right.size), INT_MAX, INT_MIN);
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        NodeInfo ret = postOrderTraversal(root);
        return ret.size;
    }
};