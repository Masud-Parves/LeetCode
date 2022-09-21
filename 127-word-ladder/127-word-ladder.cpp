class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> cache(wordList.begin(), wordList.end());
        cache.insert(beginWord);
        
        if(cache.find(endWord) == cache.end()) return 0;
        
        queue<pair<string, int>> todo;
        todo.push({beginWord,1});
        cache.erase(beginWord);
        
        while(!todo.empty()){
            auto node = todo.front();
            todo.pop();
            
            string word = node.first;
            int steps = node.second;
            
            if(word == endWord) return steps;
            
            for(int i=0; i<word.size() ; i++){
                char orginal = word[i];
                
                for(char c='a'; c<='z'; c++){
                    if(c == orginal) continue;
                    word[i] = c;
                    
                    if(cache.find(word) != cache.end()){
                        todo.push({word, steps+1});
                        cache.erase(word);
                    }
                }
                word[i] = orginal;
            }
        }
        return 0;
    }
};