typedef pair<int,pair<int,int>> piii;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int numOfNodes = passingFees.size();
        
        vector<vector<int>> DP(numOfNodes, vector<int>(maxTime+1, INT_MAX));
        vector<int> nodesTime(numOfNodes, INT_MAX);
        vector<vector<int>> graph[numOfNodes];
        for(auto& edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<piii, vector<piii>, greater<piii>> Q;
        DP[0][0] = passingFees[0];
        nodesTime[0] = 0;
        Q.push({passingFees[0], {0, 0}});
        
        
        while(!Q.empty()){
            auto node = Q.top();
            Q.pop();
            int uNode = node.second.first;
            int travelCost = node.first;
            int travelTime = node.second.second;
            
            if(uNode == numOfNodes-1){
                return travelCost;
            }
            nodesTime[uNode] = travelTime;
            for(auto child : graph[uNode]){
                int vNode = child[0];
                int time = child[1];
                
                if(travelTime + time>=nodesTime[vNode]) continue;
                if(travelTime+time<=maxTime){
                    if(travelCost+passingFees[vNode]<DP[vNode][travelTime+time]){
                        nodesTime[vNode] = travelTime+time;
                        DP[vNode][travelTime+time] = travelCost+passingFees[vNode];
                        Q.push({DP[vNode][travelTime+time], {vNode, nodesTime[vNode]}});
                    }
                }
            }
        }
        return -1;
    }
};