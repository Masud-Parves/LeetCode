class Solution {	
private:	
    int M = 1000000007;	
public:	
    int countPaths(int n, vector<vector<int>>& roads) {	
        vector<vector<pair<int, int>>> graph(n);	
        for(auto& road : roads){	
            int u = road[0], v = road[1], time = road[2];	
            graph[u].push_back({v, time});	
            graph[v].push_back({u, time});	
        }	
        	
        vector<long long>dis(n, LLONG_MAX);	
        vector<long long>paths(n);	
        	
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;	
        pq.push({0, 0});	
        dis[0] = 0;	
        paths[0] = 1;	
        	
        while(!pq.empty()){	
            pair<long long, int> curr = pq.top();	
            pq.pop();	
            int u = curr.second;	
            long long uCost = curr.first;	
            	
            for(auto& node : graph[u]){	
                int v = node.first;	
                int childCost = node.second;	
                	
                if(dis[v] > dis[u] + childCost){	
                    dis[v] = dis[u] + childCost;	
                    paths[v] = paths[u];	
                    pq.push({dis[v], v});	
                } else if(dis[v] == uCost+childCost){	
                    paths[v] = (paths[v]%M + paths[u]%M)%M;	
                }	
            }	
        }	
        	
        return paths[n-1];	
    }	
};