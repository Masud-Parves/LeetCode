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
    int isEvenValuedGrandparent(TreeNode* node){
        if(node == NULL) return 0;
        int bothSum = 0;
        if(node->left != NULL) bothSum += node->left->val;
        if(node->right != NULL) bothSum += node->right->val;
        return bothSum;
    }
public:
    int sumEvenGrandparent(TreeNode* currNode) {
        if(currNode == NULL){
            return 0;
        }
        int total = 0;
        int currVal = currNode->val;
        if(currVal%2==0){
            total += isEvenValuedGrandparent(currNode->left);
            total += isEvenValuedGrandparent(currNode->right);
        }
        
        
        total += sumEvenGrandparent(currNode->left);
        total += sumEvenGrandparent(currNode->right);
        return total;
    }
};