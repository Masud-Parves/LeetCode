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

class Trie{
private:
    TrieNode *root;
    
public:
    Trie(){
        root = new TrieNode();
    }
    
    bool insert(string& word){
        int len = word.size();
        TrieNode* curr = root;
        bool output = true;
        for(int i=0; i<len ; i++){
            int id = word[i]-'a';
            if(curr->next[id] == NULL){
                if(i!=len-1) output = false;
                curr->next[id] = new TrieNode();
 
            }
            curr = curr->next[id];
            if(i != len-1 && curr->endMark == false) output = false;
        }
        curr->endMark = true;
        return output;
    }
    
};

class Solution {
public:
    
    string longestWord(vector<string>& words) {
        
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.length()<s2.length();
        });
        
        string longestWord = "";
        int n = words.size();
        Trie* node = new Trie();
        for(auto word : words){
            if(node->insert(word)){
                if(longestWord.size() < word.size()) longestWord = word;
                else if(longestWord.size() == word.size() && word<longestWord) {
                    longestWord = word;
                }
            }
        }
        
        return longestWord;
    }
};