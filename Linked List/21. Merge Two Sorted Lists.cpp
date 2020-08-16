/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    
    struct ListNode *head= NULL, *tmp=NULL, *p=NULL;
    
    while(l1 && l2){
        if((l1->val)<=(l2->val)){
            tmp = l1;
            l1 = l1->next;
        } else {
            tmp = l2;
            l2 = l2->next;
        }
        
        tmp->next = NULL;
        if(head==NULL){
            head = tmp;
            p = tmp;
        } else {
            p->next = tmp;
            p = p->next;
        }
    }
    
    if(l1!=NULL) p->next = l1;
    if(l2!=NULL) p->next = l2;
    
    return head;
}