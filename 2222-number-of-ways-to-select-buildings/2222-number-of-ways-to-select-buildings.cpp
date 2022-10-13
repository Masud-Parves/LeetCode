class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> onePrefix(n, 0), zeroPrefix(n, 0);
        onePrefix[0] = s[0] == '1';
        zeroPrefix[0] = s[0] == '0';
        for(int i=1; i<n; i++){
            onePrefix[i] = onePrefix[i-1] + (s[i] == '1');
            zeroPrefix[i] = zeroPrefix[i-1] + (s[i] == '0');
        }
        long long totalWays = 0, leftCount = 0, rightCount;
        for(int i=1; i<n-1 ; i++){
            if(s[i] == '1'){
                leftCount = zeroPrefix[i-1];
                rightCount = zeroPrefix[n-1]-zeroPrefix[i];
                totalWays += (leftCount*rightCount);
            } else {
                leftCount = onePrefix[i-1];
                rightCount = onePrefix[n-1]-onePrefix[i];
                totalWays += (leftCount*rightCount);
            }
        }
        return totalWays;
    }
};