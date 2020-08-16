class Solution {
public:
    
    double solve(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        
        if(n%2==0){
            return solve(x*x, n/2);
        }
        return x*solve(x*x, n/2);
    }
    
    double myPow(double x, int n) {
        
        double res = solve(x, abs(n));
        
        if(n<0){
            res = (1.0/res);
        }
        return res;
    }
};