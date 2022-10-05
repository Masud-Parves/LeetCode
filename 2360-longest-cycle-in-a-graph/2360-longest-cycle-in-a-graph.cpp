class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& colors, vector<int>& cycle, int& cycledNode){

	colors[node] = 1;
	cycle.push_back(node);

	for(int vNode : graph[node]){
		if(colors[vNode] == -1){
			if(dfs(vNode, graph, colors, cycle, cycledNode) == true){
				return true;
			} 
		}else if(colors[vNode] == 1){
			cycledNode = vNode;
			return true;
		}
	}

	cycle.pop_back();
	colors[node] = 2;

	return false;
}
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>>graph(n);
        for(int i=0; i<n; i++){
            if(edges[i] == -1) continue;
            graph[i].push_back(edges[i]);
        }
        
        vector<int> colors(n, -1);
        vector<int> cycleNodes;
        int longestCycle = -1;
        for(int i=0; i<n ; i++){
            if(colors[i] == -1){
                //cout << i << endl;
                cycleNodes.clear();
                
                int startNode = -1;
                dfs(i, graph, colors, cycleNodes, startNode);
                if(startNode==-1) continue;
                int lengthOfCycle = 0;
                //cout << "start : " << startNode << endl;
                for(auto& c : cycleNodes){
                    if(c == startNode) startNode = -1;
                    if(startNode == -1){
                        lengthOfCycle++;
                    }
                }
                longestCycle = max(longestCycle, lengthOfCycle);
                cout << endl;
            }
        }
        return longestCycle==0? -1 : longestCycle;
    }
};