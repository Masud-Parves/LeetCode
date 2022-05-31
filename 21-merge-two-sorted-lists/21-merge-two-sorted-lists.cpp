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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL || list2 == NULL){
            return (list1 == NULL) ? list2 : list1;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* currNode = dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                currNode->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                currNode->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            currNode = currNode->next;
        }
        
        if(list1) currNode->next = list1;
        else if(list2) currNode->next = list2;
        
        return dummy->next;
    }
};