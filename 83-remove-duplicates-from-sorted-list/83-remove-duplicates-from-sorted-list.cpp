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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        
        ListNode* dummy = new ListNode(-200, head);
        ListNode* curr = dummy;
        
        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                ListNode* delNode = curr->next;
                curr->next = delNode->next;
                delete delNode;
            } else curr = curr->next;
        }
        return dummy->next;
    }
};