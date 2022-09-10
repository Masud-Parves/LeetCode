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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL){
            return (l1==NULL) ? l2 : l1;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;
        int carry = 0;
        while(l1 || l2){
            int currVal = ((l1 == NULL) ? 0 : l1->val) + ((l2 == NULL) ? 0 : l2->val) + carry;
            ListNode* newNode = new ListNode(currVal%10);
            carry = currVal/10;
            dummy->next = newNode;
            dummy = dummy->next;
            
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        
        if(carry != 0){
            dummy->next = new ListNode(carry);
        }
        
        return newHead->next;
    }
};