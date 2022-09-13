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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        stack<int> stk;
        ListNode* currNode = head;
        while(currNode != NULL){
            stk.push(currNode->val);
            currNode = currNode->next;
        }
        
        currNode = head;
        while(!stk.empty()){
            int lastElement = stk.top();
            stk.pop();
            if(lastElement != currNode->val) return false;
            currNode = currNode->next;
        }
        return true;
    }
};