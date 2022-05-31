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
private:
    void reverseList(ListNode* start, ListNode* end){
        if(start == NULL || start->next == NULL) return;
        
        ListNode *prevNode = NULL, *currNode = start;
        
        while(prevNode != end){
            ListNode *nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k==1){
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *beforeStart = dummy, *end = head;
        
        int idx = 0;
        
        while(end != NULL){
            
            idx++;
            if(idx%k == 0){
                ListNode *start = beforeStart->next, *afterEnd = end->next;
                
                reverseList(start, end);
                beforeStart->next = end;
                start->next = afterEnd;
                beforeStart = start;
                end = start->next;
                
            } else {
                end = end->next;
            }
        }
        
        
        return dummy->next;
    }
};