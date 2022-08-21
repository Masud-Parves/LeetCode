/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> cache;
        
        Node* root = new Node(node->val, vector<Node*>{});
        cache[node] = root;
        
        queue<Node*>Q;
        Q.push(node);
        
        while(!Q.empty()){
            Node* curr = Q.front();
            Q.pop();
            
            for(auto& child : curr->neighbors){
                if(cache.find(child) == cache.end()){
                    cache[child] = new Node(child->val, vector<Node*>{});
                    Q.push(child);
                }
                cache[curr]->neighbors.push_back(cache[child]);
            }
        }
        
        return root;
    }
};