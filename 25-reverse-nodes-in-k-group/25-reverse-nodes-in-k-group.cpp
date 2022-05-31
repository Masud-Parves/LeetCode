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
        
        ListNode *start = head, *end = head;
        int inc = k-1;
        
        while(inc--){
            end = end->next;
            if(end == NULL) return head;
        }
        ListNode *newHead = reverseKGroup(end->next, k);
        reverseList(start, end);
        start->next = newHead;
        return end;
    }
};