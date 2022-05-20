class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        vector<vector<int>>DP(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=m ; j++){
                if(str1[i-1] == str2[j-1]){
                    DP[i][j] = 1 + DP[i-1][j-1];
                } else {
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                }
            }
        }
        
        int i=n, j=m;
        string result = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                result += str1[i-1];
                i--;
                j--;
            } else if(DP[i-1][j] > DP[i][j-1]) {
                result += str1[i-1];
                i--;
            } else {
                result += str2[j-1];
                j--;
            }
        }

       while(i>0){
           result += str1[i-1];
           i--;
       }
        
        while(j>0){
            result += str2[j-1];
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};