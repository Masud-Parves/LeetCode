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
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        
        
        ListNode *fast = head, *slow = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        ListNode *prevNode = NULL, *currNode = slow;
        
        while(currNode != NULL){
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        ListNode *first = head, *second=prevNode, *tmp;
        while(second->next!= NULL){
            tmp = first->next;
            first->next = second;
            first = tmp;
            
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
        
        return;
    }
};