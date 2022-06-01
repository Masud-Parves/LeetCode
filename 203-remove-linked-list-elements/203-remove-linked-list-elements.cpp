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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* tail = dummy;
        
        while(tail && tail->next != NULL){
            if(tail->next->val == val){
                ListNode* toDelete = tail->next;
                tail->next = toDelete->next;
                delete toDelete;
            } else tail = tail->next;
        }
        return dummy->next;
    }
};