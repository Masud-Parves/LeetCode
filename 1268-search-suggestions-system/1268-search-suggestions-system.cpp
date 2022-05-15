class TrieNode{
public:
    TrieNode* next[26];
    bool endMark;
    
    TrieNode(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
        endMark = false;
    }
};


class Solution {
private:
    void generateTrie(vector<string>& products, TrieNode* root){

        for(auto product : products){
            TrieNode* curr = root;
            
            for(auto c : product){
                int id = c - 'a';
                if(curr->next[id] == NULL){
                    curr->next[id] = new TrieNode();
                }
                curr = curr->next[id];
            }
            curr->endMark = true;
        }
    }
    
    vector<string> getWordsStartingWith(string& prefix, TrieNode* root){
        TrieNode* curr = root;
        
        vector<string>result;
        
        for(auto c : prefix){
            int id = c - 'a';
            if(curr->next[id] == NULL){
                return result;
            }
            curr = curr->next[id];
        }
        
        dfsTraversal(curr, prefix, result);
        
        return result;
    }
    
    void dfsTraversal(TrieNode* node, string& prefix, vector<string>& result){
        if(result.size() == 3){
            return;
        }
        
        if(node->endMark == true){
            result.push_back(prefix);
        }
        
        // all posible paths
        for(int id = 0; id<26; id++){
            if(node->next[id]){
                prefix += (char)(id+'a');
                dfsTraversal(node->next[id], prefix, result);
                prefix.pop_back();
            }
        }
        return;
    }
    
    
public:
    
    // Time Complexity : 
    // O(n*m) for generateTrie(), where n is number of products, m is length of product. 
    // O(p) for getWordsStartingWith() , where p is length of prefix string.
    // O(h) for dfsTraversal(), where h is depth of trie, which is nothing but maximum height of trie.
    
    // Space Complexity : O(26*26*26..... so on), ~ O(26n) ~ O(n), where n is maximum length of products string.
    // because every TrieNode has atmost 26 child and every child has atmost 26 child.
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        
        generateTrie(products, root);
        vector<vector<string>> results;
        string prefix = "";
        for(auto c : searchWord){
            prefix += c;
            
            vector<string> segment = getWordsStartingWith(prefix, root);
            results.push_back(segment);
        }
        
        return results;
    }
};