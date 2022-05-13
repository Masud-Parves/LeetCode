/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *leftMost, *prev;
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        
        leftMost = root;
        while(leftMost!=NULL){
            Node* curr = leftMost;
            leftMost = prev = NULL;
            
            while(curr!=NULL){
                buildTree(curr->left);
                buildTree(curr->right);
                curr = curr->next;
            }
        }
        return root;
    }
    
    void buildTree(Node* curr){
        if(curr!=NULL){
            if(prev == NULL){
                leftMost = curr;
            } else {
                prev->next = curr;
            }
            prev = curr;
        }
    }
};