class Solution {
public:
    int tribonacci(int n) {
        if(n<3){
            return n==0 ? 0 : 1;
        }
        
        vector<int>T(n+1);
        T[0] = 0;
        T[1] = T[2] = 1;
        for(int i=3; i<=n; i++){
            T[i] = T[i-1] + T[i-2] + T[i-3];
        }
        return T[n];
    }
};