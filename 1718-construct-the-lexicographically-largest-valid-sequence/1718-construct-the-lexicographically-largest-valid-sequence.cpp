class Solution {
private:
    bool backtrack(int idx, int left, vector<bool>& visited, vector<int>& res, int n){
        if(left==0){
            return true;
        }
        
        if(res[idx] != -1){
            return backtrack(idx+1, left, visited, res, n);
        }

        for(int i=n; i>=1; i--){
            if(visited[i] == true) continue;
            
            if(i == 1){
                visited[i] = true;
                res[idx] = 1;
                if(backtrack(idx+1, left-1, visited, res, n)) return true;
                res[idx] = -1;
                visited[i] = false;
            } else {
                
                if(idx + i>=res.size() || res[idx+i]!= -1) continue;
                
                visited[i] = true;
                res[idx] = i;
                res[idx+i] = i;
                if(backtrack(idx+1, left-2, visited, res, n)) return true;
                res[idx] = -1;
                res[idx+i] = -1;
                visited[i] = false;
            }
            
        }
        
        
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1, -1);
        vector<bool> visited(n+1, false);
        
        backtrack(0, 2*n-1, visited, result, n);
        return result;
    }
};