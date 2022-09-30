class Solution {
private:
    bool dfs(int uNode, vector<vector<int>>& graph, vector<int>& color, stack<int>& order){        
        color[uNode] = 1;
        for(auto& vNode : graph[uNode]){
            if(color[vNode] == -1 && dfs(vNode, graph, color, order) == true){ // cycle dected so topo sort not possible
               return true; 
            } else if(color[vNode] == 1){
                return true;
            }
        }
        color[uNode] = 2;
        order.push(uNode);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& course : prerequisites){
            graph[course[1]].push_back(course[0]);
        }
        
        vector<int> color(numCourses, -1);
        stack<int> topo;
        
        for(int i=0; i<numCourses; i++){
            if(color[i] == -1){
                if(dfs(i, graph, color, topo) == true){ // got cycle so topo sort not possible
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