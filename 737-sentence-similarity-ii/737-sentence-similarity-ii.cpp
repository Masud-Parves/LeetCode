class Union_Find{
public:
    Union_Find(int sz) : root(sz), rank(sz){
        for(int i=0; i<sz; i++){
            root[i] = i;
        }
    }
    
    int Find(int x){
        if(x == root[x]){
            return x;
        }
        return root[x] = Find(root[x]);
    }
    
    void Union(int x, int y){
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX != rootY){
            root[rootX] = rootY;
        }
    }
private:
    vector<int> root;
    vector<int> rank;
};


class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()){
            return false;
        }
        unordered_map<string, int> cache;
        int id = 0;
        for(auto& pair : similarPairs){
            string word1 = pair[0];
            string word2 = pair[1];
        
            if(cache.find(word1) == cache.end()) cache[word1] = id++;
            if(cache.find(word2) == cache.end()) cache[word2] = id++;
        }
        
        Union_Find dsu(id+1);
        for(auto& pair : similarPairs){
            string word1 = pair[0];
            string word2 = pair[1];
            

            dsu.Union(cache[word1], cache[word2]);
        }
        
        for(int i=0; i<sentence1.size() ; i++){
            string word1 = sentence1[i];
            string word2 = sentence2[i];
            if(word1 == word2) continue;
            if(cache.find(word1) == cache.end() || cache.find(word2) == cache.end()) return false;
            if(dsu.Find(cache[word1]) != dsu.Find(cache[word2])){
                return false;
            }
        }
        return true;
    }
};