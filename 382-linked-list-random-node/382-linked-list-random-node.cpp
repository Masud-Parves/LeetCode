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
    vector<int> nums;
    int lenOfList;
    void listToArray(ListNode* head){
        ListNode* currNode = head;
        while(currNode != NULL){
            nums.push_back(currNode->val);
            currNode = currNode->next;
        }
        return;
    }
public:
    Solution(ListNode* head) {
        listToArray(head);
        lenOfList = nums.size();
    }
    
    int getRandom() {
        int idx = rand()%lenOfList;
        return nums[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */