class MyLinkedList {
private:
    ListNode* head;
    int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    void printList(ListNode* node){
        ListNode* curr = node;
        while(curr != NULL){
            cout << curr->val << " ->";
            curr = curr->next; 
        }
    }
    int get(int index) {
        if(index<0 or index>=size) return -1;
        ListNode* curr = head;
        for(int i = 0; i<index; i++){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newOne = new ListNode(val);
        
        if(head==NULL){
            head = newOne;
        } else {
            newOne->next = head;
            head = newOne;
        }
        size++;
    }
    
    void addAtTail(int val) {
        if(size == 0){
            addAtHead(val);
            return;
        }
        ListNode* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        
        ListNode* newNode = new ListNode(val);
        curr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        if(index == 0){
            addAtHead(val);
            return;
        } else if(index == size) {
            addAtTail(val);
            return;
        }
        ListNode* curr = head;
        for(int i=1; i<index; i++){
           curr = curr->next;
        }
        
        ListNode* newNode = new ListNode(val, curr->next);
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 or index>=size) {
            return;
        }
        if(index == 0){
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            size--;
            return;
        }
        
        ListNode* curr = head;
        for(int i=1; i<index; i++){
            curr = curr->next;
        }
        
        ListNode* delNode = curr->next;
        curr->next = delNode->next;
        delete delNode;
        //printList(head);
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */