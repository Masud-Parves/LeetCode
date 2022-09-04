class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int>outDegree(n, 0);
        
        unordered_map<int, set<int>> directly;
        
        for(auto& road : roads){
            outDegree[road[0]]++;
            outDegree[road[1]]++;
            directly[road[0]].insert(road[1]);
            directly[road[1]].insert(road[0]);
        }
        
        int networkRank = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1 ; j<n;  j++){
                int currRank = outDegree[i] + outDegree[j] - (directly[i].find(j) != directly[i].end());
                networkRank = max(networkRank, currRank);
            }
        }
        return networkRank;
    }
};