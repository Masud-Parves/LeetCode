class TrieNode{
public:
    TrieNode* next[26];
    bool endMark;
    
    TrieNode(){
        for(int i=0; i<26 ; i++){
            next[i] = NULL;
        }
        endMark = false;
    }
};

class Solution {
private:
    TrieNode* root;
public:
    
    void insert(string word){
        int len = word.size();
        TrieNode* curr = root;
        
        for(int i=0; i<len ; i++){
            int id = word[i] - 'a';
            if(curr->next[id] == NULL){
                curr->next[id] = new TrieNode();
            }
            curr = curr->next[id];
        }
        curr->endMark = true;
    }
    
    
    bool search(string word){
        int len = word.size();
        TrieNode* curr = root;
        
        for(int i=0; i<len ; i++){
            int id = word[i] - 'a';
            if(curr->next[id] == NULL){
                return  false;
            }
            curr = curr->next[id];
        }
        return curr->endMark;
    }
    
    bool find(string s, int start, vector<int>& DP){
        int &cache = DP[start];
        if(cache != -1) return cache;
        
        if(start==s.length()){
            return cache = 1;
        }
        
        for(int end=start+1 ; end<=s.size(); end++){
            
            if(search(s.substr(start, end-start)) && find(s, end, DP)){
                return cache = true;
            }
        }
        return cache = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        root = new TrieNode();
        vector<int>DP(n+1, -1);
        for(string word : wordDict){
            insert(word);
        }
        
        return find(s, 0, DP);
        
    }
};