class Solution {
private:
    int helper(int n, int k, int pColor, int consCount, unordered_map<string, int>& DP){
        if(n==0) return 1;
        if(consCount == 2) return 0;
        
        string state = to_string(n) + "$" + to_string(consCount);
        if(DP.find(state) != DP.end()){
            return DP[state];
        }
        
        int& cache = DP[state];
        
        cache = helper(n-1, k, pColor, consCount+1, DP);
        for(int c = 0; c<k; c++){
            if(c == pColor) continue;
            cache += helper(n-1, k, c, 0, DP); 
        }
        
        return cache;
    }
public:
    int numWays(int n, int k) {
        unordered_map<string, int> DP;
        return helper(n, k, 0, 0, DP);
    }
};