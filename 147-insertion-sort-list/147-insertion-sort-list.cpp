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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN, head);
        
        
        ListNode *prev = head, *curr = head->next;
        
        while(curr != NULL){
            if(curr->val < prev->val){
                ListNode* node = curr;
                prev->next = curr->next;
                
                ListNode* tmp = dummy;
                while(node->val>tmp->next->val){
                    tmp = tmp->next;
                }
                ListNode* hold_next = tmp->next;
                tmp->next = node;
                node->next = hold_next;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};