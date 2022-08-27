class Solution {
public:
    int countPairs(vector<int>& deli) {
        int n = deli.size();
        int result;
        int MOD = 1e9+7;
        unordered_map<int, int> seen;
        for(int i=0; i<n; i++){
            
            for(int p = 0; p<=21; p++){
                int powerOfTwo = (1<<p);
                
                int need = powerOfTwo - deli[i];
                if(seen.find(need) != seen.end()){
                    result = ((result%MOD) + (seen[need]%MOD))%MOD;
                }   
            }
            seen[deli[i]]++;
        }
        return result;
    }
};