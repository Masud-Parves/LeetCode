class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> seen(wordList.begin(), wordList.end());
        seen.insert(beginWord);
        
        queue<pair<string, int>> Q;
        Q.push({beginWord, 1});
        
        while(!Q.empty()){
            auto node = Q.front();
            Q.pop();
            string word = node.first;
            int step = node.second;
            
            if(word == endWord){
                return step;
            }
            
            for(int i=0; i<word.size(); i++){
                char orginal = word[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    if(ch == orginal) continue;
                    word[i] = ch;
                    if(seen.find(word) != seen.end()){
                        seen.erase(word);
                        Q.push({word, step+1});
                    }
                }
                word[i] = orginal;
            }
        }
        return 0;
    }
};