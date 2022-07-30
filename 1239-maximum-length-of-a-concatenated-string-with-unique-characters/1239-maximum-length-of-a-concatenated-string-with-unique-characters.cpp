class Solution {
private:
    int max(int a, int b){
        if(a>=b) return a;
        return b;
    }
    bool unique(string& word){
        unordered_map<char, bool> seen;
        
        for(auto& c : word){
            if(seen.find(c) != seen.end()){
                return false;
            }
            seen[c] = true;
        }
        return true;
    }
    
    bool canBeTaken(string& word, string& visited){
        for(int i=0; i<word.size(); i++){
            int id = word[i]-'a';
            if(visited[id] != '0') return false;
        }
        return true;
    }
    
    void take(string& word, string& visited, bool include){
        for(int i=0; i<word.size(); i++){
            int id = word[i]-'a';
            if(include) visited[id] = '1';
            else visited[id] = '0';
        }
    }
    void pop(string& currSeq, int n){
        for(int i=0; i<n; i++){
            currSeq.pop_back();
        }
    }
    void backtrack(int idx, vector<string>& words, string& visited, string currSeq, int& result){
        if(idx == words.size()){
            result = max(currSeq.size(), result);
            return;
        }
        
        if(canBeTaken(words[idx], visited)){
            take(words[idx], visited, true);
            currSeq += words[idx];
            
            backtrack(idx+1, words, visited, currSeq, result);
            
            currSeq.erase(currSeq.size()-words[idx].size());
            take(words[idx], visited, false);
        }
        backtrack(idx+1, words, visited, currSeq, result);
        
    }
    
    
public:
    int maxLength(vector<string>& arr) {
        vector<string> words;
        
        for(auto& word : arr){
            if(unique(word)){
                words.push_back(word);
            }
        }
        
        string visited(26, '0');
        //cout << visited << endl;
        
        int result = 0;
        backtrack(0, words, visited, "", result);
        
        return result;
    }
};