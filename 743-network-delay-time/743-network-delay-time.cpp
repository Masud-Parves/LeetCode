class Solution {
public:
    vector<pair<int, int>>adj[101];

    void dijkstra(int src, vector<int>&dis){
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        dis[src] = 0;
        
        while(!pq.empty()){
            int currNode = pq.top().second;
            int currTime = pq.top().first;
            pq.pop();
            
            for(auto edge : adj[currNode]){
                int childNode = edge.second;
                int childTime = edge.first;
                
                if(dis[childNode]>currTime + childTime){
                    dis[childNode] = currTime + childTime;
                    pq.push({dis[childNode], childNode});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto time : times){
            int src = time[0];
            int des = time[1];
            int curTime = time[2];
            adj[src].push_back({curTime , des});
        }
        
        
        vector<int> dis(n+1, INT_MAX);
        
        dijkstra(k, dis);
        int answer = INT_MIN;
        for(int i=1; i<=n ; i++){
            answer = max(answer, dis[i]);
        }
        return answer == INT_MAX ? -1 : answer;
    }
};