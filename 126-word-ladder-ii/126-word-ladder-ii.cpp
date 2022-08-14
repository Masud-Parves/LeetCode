class Solution {
private:
    bool check(string& a, string b){
        if(a.size() != b.size()) return false;
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]) cnt++;
        }
        return cnt==1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> shortestPaths;
        int n = wordList.size();
        int startNode = -1, endNode = -1;
        for(int i=0; i<n ; i++){
            if(wordList[i] == beginWord) {
                startNode = i;
            }
            if(wordList[i] == endWord){
                endNode = i;
            }
        }
        
        if(endNode == -1){
            return shortestPaths;
        }
        if(startNode == -1) {
            wordList.emplace(wordList.begin(), beginWord);
            startNode = 0;
            n++;
            endNode++;
        }
        
        vector<vector<int>>graph(n);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(check(wordList[i], wordList[j]) == true){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> parent[n];
        bfs(startNode, graph, parent, endNode, n);
        vector<int>path;
        vector<vector<int>> paths;
        backtrack(paths, path, parent, endNode);
        
        for(auto u:paths){
            vector <string> now;
            for(int i=0;i<u.size()-1;i++)
                now.push_back(wordList[u[i]]);
            reverse(now.begin(),now.end());
            now.push_back(wordList[endNode]);
            shortestPaths.push_back(now);
        }
        
        return shortestPaths;
    }
    
    void backtrack(vector<vector<int>>& paths, vector<int>& path, vector<int> parent[], int node){
        if(node == -1){
            paths.push_back(path);
            return;
        }
        
        
        for(int p : parent[node]){
            path.push_back(p);
            backtrack(paths, path, parent, p);
            path.pop_back();
        }
    }
    void bfs(int src, vector<vector<int>>& graph, vector<int> parent[], int des, int n){
        
        vector<int> dis(n, 10000);
        queue<int>q;
        q.push(src);
        parent[src] = {-1};
        dis[src] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v : graph[u]){
                if(dis[v]>dis[u]+1){
                    dis[v] = dis[u]+1;
                    q.push(v);
                    parent[v].clear();
                    parent[v].push_back(u);
                } else if(dis[v] == dis[u]+1){
                    parent[v].push_back(u);
                }
            }
        }
        return;
    }
    
    
    
    
};