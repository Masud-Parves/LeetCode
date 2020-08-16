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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode *dammy = new ListNode(0);
        dammy->next = head;
        
        ListNode *cur = dammy;
        ListNode *P = NULL, *Q = NULL;
        while(cur && cur->next && cur->next->next){
            P = cur->next;
            Q = cur->next->next;
            
            cur->next = Q;
            P->next = Q->next;
            Q->next = P;
            
            cur = cur->next->next;
        }
        return dammy->next;
        
    }
};