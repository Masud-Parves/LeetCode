class Solution {
public:
    int numSquares(int n) {
        if(n == 1 || n==2) return n;
        vector<int>coins;
        int i = 1;
        while(i*i<=n){
            coins.push_back(i*i);
            i++;
        }
        int amount = n;
        n = coins.size();

        vector<int>previous(amount+1);
        vector<int>current(amount+1);
        
        for(int tar = 0; tar<=amount; tar++){
            previous[tar] = (tar%coins[0] == 0) ? tar/coins[0] : INT_MAX/2;
        }
        
        for(int idx=1; idx<n ;idx++){
            for(int tar = 0; tar<=amount; tar++){
                current[tar] = previous[tar];
                if(coins[idx]<=tar){
                    current[tar] = min(current[tar], 1 + current[tar-coins[idx]]);
                }
            }
            previous = current;
        }
        
        return previous[amount];
    }
};