class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& path, stack<int>& topo){
        
        visited[node] = path[node] = true;
        
        for(auto& vNode : graph[node]){
            if(visited[vNode] == false){
                if(dfs(vNode, graph, visited, path, topo) == false){
                    return false;
                }
            } else if(path[vNode] == true) {
                return false;
            }
        }
        path[node] = false;
        topo.push(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& course : prerequisites){
            graph[course[1]].push_back(course[0]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        stack<int> topo;
        
        for(int i=0; i<numCourses; i++){
            if(visited[i] == false){
                if(dfs(i, graph, visited, path, topo) == false){
                    return vector<int>();
                }
            }
        }
        
        vector<int> result;
        while(!topo.empty()){
            result.push_back(topo.top());
            topo.pop();
        }
        return result.size() == numCourses ? result : vector<int>();
    }
};