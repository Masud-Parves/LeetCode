class Solution {
private:
    
    void topologicalSort(vector<vector<int>>& graph, vector<int>& indegree, vector<int>& quiet, vector<int>& answer){
        int n = answer.size();
        queue<int> todo;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                todo.push(i);
            }
        }
        
        
        while(!todo.empty()){
            int uNode = todo.front();
            todo.pop();
            
            for(int vNode : graph[uNode]){
                int uNodeVal = quiet[answer[uNode]];
                int vNodeVal = quiet[answer[vNode]];
                if(uNodeVal<vNodeVal){
                    answer[vNode] = answer[uNode];
                }
                indegree[vNode]--;
                if(indegree[vNode] == 0) {
                    todo.push(vNode);
                }
            }
        }
        return;
    }
    
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        
        vector<int> answer(n);
        for(int i=0; i<n; i++){
            answer[i] = i;
        }

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(auto& edge : richer){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        topologicalSort(graph, indegree, quiet, answer);
        return answer;
    }
};