class Solution {
public:
    int minOperations(int n) {
        int total = 0;
        
        for(int i=0; i<n; i++){
            total += (i*2+1);
        }
        int avg = total/n;
        int minMove = 0;
        for(int i=1; i<=n/2; i++){
            int currVal = (n-i)*2+1;
            minMove += (currVal-avg);
        }
        return minMove;
    }
};