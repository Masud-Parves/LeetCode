class Solution {
private:
    
    bool buildGraph(vector<string>& words, vector<vector<int>>& graph, vector<int>& inorder, vector<bool>& seen, int& node){
        int n = words.size();
        inorder.resize(26, 0);
        graph.resize(26);
        seen.resize(26, false);
        for(int i=0; i<n; i++){
            bool take = false;
            
            for(int k=0; k<words[i].size(); k++){
                if(seen[words[i][k]-'a'] == false){
                    seen[words[i][k]-'a'] = true;
                    node++;
                }
            }
            if(i == words.size()-1) break;
            for(int k=0; k<min(words[i].size(), words[i+1].size()); k++){
                if(words[i][k] != words[i+1][k]){
                    int u = words[i][k]-'a', v = words[i+1][k]-'a';
                    graph[u].push_back(v);
                    inorder[v]++;
                    take = true;
                    break;
                }
            }
            if(take != true && words[i].size()>words[i+1].size()){
                cout << "Ase" << endl;
                return false;
            }
        }
        return true;
    }
    
    void topologicalSort(vector<vector<int>>& graph, vector<int>& inorder, vector<bool>& seen, string& result, int node){
        queue<int>Q;
        for(int i=0; i<26; i++){
            if(inorder[i]==0 && seen[i] == true){
                Q.push(i);
            }
        }
        if(Q.size() == 0){
            return;
        }
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            
            result += (char)(u+'a');
            
            for(int v : graph[u]){
                inorder[v]--;
                if(inorder[v] == 0){
                    Q.push(v);
                }
            }
            
        }
        result = (result.size() == node) ? result : "";
        return;
    }
    
public:
    string alienOrder(vector<string>& words) {
        string result = "";
        vector<vector<int>>graph;
        vector<int>inorder;
        vector<bool>seen;
        int node = 0;
        bool ret = buildGraph(words, graph, inorder, seen, node);
        if(ret == false) return result;
        
        topologicalSort(graph, inorder, seen, result, node);
        return result;
    }
};