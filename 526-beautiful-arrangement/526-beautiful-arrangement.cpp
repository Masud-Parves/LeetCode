class Solution {
private:
    void generatePermutations(int& take, int n, vector<bool>& seen, int& ret){
        if(take == n){
            ret++;
            return;
        }
    
    
        for(int i=1; i<=n ;i++){
            if(seen[i] == false){
                int sz = take+1;
                if(i%sz == 0 || sz%i == 0) {
                    seen[i] = true;
                    take++;
                    generatePermutations(take, n, seen, ret);
                    take--;
                    seen[i] = false;
                }
            }
        }
    
    
    }
public:
    int countArrangement(int n) {
        vector<vector<int>> permutations;
        
        int take = 0;
        vector<bool> seen(n+1, false);
        int ret = 0;
        generatePermutations(take, n, seen, ret);
        
        return ret;
    }
};