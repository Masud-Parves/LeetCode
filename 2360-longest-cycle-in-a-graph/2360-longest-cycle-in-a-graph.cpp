class Solution {
private:
   bool dfs(int uNode, vector<vector<int>>& graph, vector<int>& colors){
       colors[uNode] = 1;
       
       for(int vNode : graph[uNode]){
           if(colors[vNode] == -1){
               if(dfs(vNode, graph, colors) == true){
                   return true;
               }
           } else if(colors[vNode] == 1){
               return true;
           }
       }
       
       colors[uNode] = 2;
       return false;
   }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>>graph(n);
        for(int i=0; i<n; i++){
            if(edges[i] == -1) continue;
            graph[edges[i]].push_back(i);
        }
        
        vector<int> colors(n, -1);
        int longestCycle = -1;
        for(int i=0; i<n ; i++){
            bool isCycle = false;
            if(colors[i] == -1){
                isCycle = dfs(i, graph, colors);
            }
            int currCycleLength = 0;
            if(isCycle){
                
                int node = i;
                currCycleLength++;
                while(i != edges[node]){
                    currCycleLength++;
                    node = edges[node];
                }
                
                
            }
            longestCycle = max(longestCycle, currCycleLength);
        }
        return longestCycle==0? -1 : longestCycle;
    }
};