class Solution {
private:
    void generatePermutations(vector<int>& perms, int n, unordered_map<int, bool>& seen, int& ret){
        if(perms.size() == n){
            ret++;
            return;
        }
    
    
        for(int i=1; i<=n ;i++){
            if(seen[i] == false){
                int sz = perms.size()+1;
                if(i%sz == 0 || sz%i == 0) {
                    seen[i] = true;
                    perms.push_back(i);
                    generatePermutations(perms, n, seen, ret);
                    perms.pop_back();
                    seen[i] = false;
                }
            }
        }
    
    
    }
public:
    int countArrangement(int n) {
        vector<vector<int>> permutations;
        
        vector<int> perms;
        unordered_map<int, bool>seen;
        int ret = 0;
        generatePermutations(perms, n, seen, ret);
        
        return ret;
    }
};