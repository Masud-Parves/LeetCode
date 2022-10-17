class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        //0110001
        vector<int>prefix(n, 0);
        prefix[0] = (s[0] == '0');
        int cntZero = 0;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1]+ (s[i] == '0');
            if(s[i] == '0'){
                cntZero++;
            }
        }
        
        int minFlips = INT_MAX;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                int leftOne = i - prefix[i] + 1;
                int rightZero = prefix[n-1] - prefix[i];
                minFlips = min(minFlips, leftOne+rightZero);
            }
        }
        return min(minFlips, cntZero);
    }
};