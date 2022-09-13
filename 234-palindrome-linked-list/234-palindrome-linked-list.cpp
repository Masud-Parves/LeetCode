/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 Algorithm : 
 
    1. Find midNode 
    2. reverse midNode -> lastNode
    3. 
 
 */
class Solution {
private:
    ListNode* middleOfList(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode *prevNode = NULL, *currNode = head, *nextNode;
        while(currNode != NULL){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }
        ListNode* currHead = head;
        ListNode* middleNode = middleOfList(currHead);
        middleNode->next = reverseList(middleNode->next);
        
        
        bool isPali = true;
        ListNode* left = head, *right = middleNode->next;
        while(right != NULL){
            if(left->val != right->val){
                isPali = false;
                break;
            }
            left = left->next;
            right = right->next;
        }
        
        middleNode->next = reverseList(middleNode->next);
        return isPali;
    }
};