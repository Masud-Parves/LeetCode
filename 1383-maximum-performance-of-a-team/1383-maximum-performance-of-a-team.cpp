

class Solution {
private:
    int MOD = 1000000007;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> store;
        for(int i=0; i<n; i++){
            store.push_back({efficiency[i], speed[i]});
        }
        
        priority_queue<int, vector<int>, greater<int>> Q;
        
        sort(store.rbegin(), store.rend());
        
        long long totalSpeed = 0, currSpeed = 0, result = 0;
        for(auto& engineer : store){
            
            totalSpeed += engineer.second;
            
            Q.push(engineer.second);
            if(Q.size()>k){
                totalSpeed -= Q.top();
                Q.pop();
            }
            
            result = max(result, totalSpeed*engineer.first);
        }
        return result%MOD;
    }
};