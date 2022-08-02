class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        if(n==1){
            return 1;
        }
        vector<vector<int>> graph(n+1);
        vector<int>inorder(n+1, 0);
        for(auto& edge : relations){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            inorder[v]++;
        }
        
        queue<int>Q;
        
        
        for(int i=1; i<=n; i++){
            if(inorder[i] == 0){
                Q.push(i);
            }
        }
        int semester = 0;
        int node = 0;
        while(!Q.empty()){
            int sz = Q.size();
            semester++;
            
            for(int i=0; i<sz; i++){
                int u = Q.front();
                Q.pop();
                node++;
                for(auto& v : graph[u]){
                    inorder[v]--;
                    if(inorder[v]==0) Q.push(v);
                }
            }
            
        }
        return node == n ? semester : -1;
    }
};