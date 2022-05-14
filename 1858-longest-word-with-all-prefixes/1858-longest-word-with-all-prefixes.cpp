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
    
    void insert(string& word){
        int len = word.size();
        TrieNode* curr = root;
        
        for(int i=0; i<len ; i++){
            int id = word[i]-'a';
            if(curr->next[id] == NULL){
                curr->next[id] = new TrieNode();
            }
            
            curr = curr->next[id];
        }
        curr->endMark = true;
    }
    
    bool search(string& word){
        int len = word.size();
        TrieNode* curr = root;
        
        for(int i=0; i<len ; i++){
            int id = word[i]-'a';
            if(curr->next[id] == NULL){
                return false;
            }
            curr = curr->next[id];
            if(curr->endMark == false) return false;
        }
        return curr->endMark;
    }
    
    
    string longestWord(vector<string>& words) {
        root = new TrieNode();

        for(auto word : words){
            insert(word);
        }
        string longestWord = "";
        for(auto word : words){
            if(search(word)){
                if(word.size()>longestWord.size()){
                    longestWord = word;
                } else if(word.size() == longestWord.size() && word<longestWord){
                    longestWord = word;
                }
            }
        }
        return longestWord;
    }
};