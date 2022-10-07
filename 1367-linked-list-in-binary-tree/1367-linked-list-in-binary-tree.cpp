/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfsTraversal(TreeNode* root, ListNode* head){
        if(head == NULL) return true;
        if(root == NULL) return false;
        int currRootVal = root->val, currHeadVal = head->val;
        if(currRootVal == currHeadVal){
            bool left = dfsTraversal(root->left, head->next);
            bool right = dfsTraversal(root->right, head->next);
            return left || right;
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL && head == NULL) return true;
        if(root == NULL || head == NULL) return false;
        
        return dfsTraversal(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};