class LRUCache {

public:
class ListNode{
    public:
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int key, int val){
            this->key = key;
            this->val = val;
        }
    };

    int capacity, currSize;
    unordered_map<int, ListNode*> address;
    
    ListNode *head = new ListNode(-1, -1);
    ListNode *tail = new ListNode(-1, -1);

    LRUCache(int maxSize) {
        capacity = maxSize;
        currSize = 0;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(ListNode* currNode){
        ListNode* prevNode = currNode->prev;
        ListNode* nextNode = currNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNodeAtFront(ListNode* currNode){
        currNode->next = head->next;
        currNode->prev = head;
        currNode->next->prev = currNode;
        head->next = currNode;
    }

    int get(int key) {
        int value = -1;
        if(address.find(key) != address.end() && address[key] != NULL) {
            ListNode* currNode = address[key];
            value = currNode->val;
            deleteNode(currNode);
            addNodeAtFront(currNode);
            address[key] = head->next;
        }
        return value;
    }
    
    void put(int key, int value) {
        if(address.find(key) != address.end()){
            ListNode* currNode = address[key];
            deleteNode(currNode);
            address.erase(key);
            currSize--;
        }

        if(currSize == capacity){
            ListNode* leastUse = tail->prev;
            address.erase(leastUse->key);
            deleteNode(leastUse);
            currSize--;
        }
        ListNode* currNode = new ListNode(key, value);
        addNodeAtFront(currNode);
        address[key] = head->next;
        currSize++;
        return;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */