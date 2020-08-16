class Solution {
public:
    int DP[50], target;
    int solve(int pos){
        if(pos==target) return 1;
        if(pos>target) return 0;
        
        int &res = DP[pos];
        if(res!=-1) return res;
        
        res = 0;
        
        if(pos+1<=target){
            res += solve(pos+1);
        } 
        if(pos+2<=target){
            res += solve(pos+2);
        }
        return res;
    }
    
    int climbStairs(int n) {
        
        memset(DP, -1, sizeof(DP));
        target = n;
        int ret = solve(0);
        
        return ret;
        
    }
};