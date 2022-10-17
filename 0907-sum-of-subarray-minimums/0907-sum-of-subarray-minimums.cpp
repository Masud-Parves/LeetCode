class Solution {
private: 
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n), right(n);
        
        stack<int> stack;
        left[0] = 1;
        stack.push(0);
        for(int i=1; i<n; i++){
            if(stack.empty()){
                left[i] = i+1;
            } else {
                while(!stack.empty() && arr[stack.top()]>=arr[i]) stack.pop();
                
                if(stack.empty()){
                    left[i] = i+1;
                } else {
                    left[i] = i - stack.top();
                }
            }
            stack.push(i);
        }
        
        while(!stack.empty()) stack.pop();
        
        stack.push(n-1);
        right[n-1] = 1;
        
        for(int i=n-2; i>=0 ; i--){
            if(stack.empty()){
                right[i] = n-i;
            } else {
                while(!stack.empty() && arr[stack.top()]>arr[i]) stack.pop();
                
                if(stack.empty()){
                    right[i] = n-i;
                } else {
                    right[i] = stack.top()-i;
                }
            }
            stack.push(i);
        }
        int total = 0;
        
        for(int i=0; i<n; i++){
            long long prod = (left[i]*right[i])%mod;
            prod = (prod*arr[i])%mod;
            total = (total + prod)%mod;
        }
        return total;
    }
};