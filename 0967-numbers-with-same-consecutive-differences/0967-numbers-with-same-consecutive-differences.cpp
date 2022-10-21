class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        
        unordered_map<long long, bool> visited;
        
        queue<long long> todo;
        int level = 0;
        
        for(int i=1; i< 10; i++){
            todo.push(i);
            visited[i] = true;
        }
        while(!todo.empty()){
            
            if(level == n) break;
            level++;
            
            int size = todo.size();
            for(int i=0; i<size; i++){
                long long currVal = todo.front();
                todo.pop();
                
                if(level == n){
                    result.push_back(currVal);
                }
                
                
                
                int lastDigit = currVal%10;
                int nextDigit = lastDigit + k;
                int prevDigit = lastDigit-k;
                long long nextVal = -1;
                
                if(nextDigit<10){
                    
                    nextVal = currVal*10LL+nextDigit;
                    if(visited.find(nextVal) == visited.end()){
                        visited[nextVal] = true;
                        todo.push(nextVal);
                    }
                    
                }
                if(prevDigit>=0){
                    nextVal = currVal*10LL+prevDigit;
                    if(visited.find(nextVal) == visited.end()){
                        todo.push(nextVal);
                        visited[nextVal] = true;
                    }
                }
            }
            
        }
        
        
        return result;
    }
};