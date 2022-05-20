class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<double> previousRow(m+1, 0);
        vector<double> currentRow(m+1, 0);
        
        previousRow[0] = currentRow[0] = 1;

        for(int i=1; i<=n ; i++){
            for(int j=1; j<=m; j++){
                currentRow[j] = previousRow[j];
                if(s[i-1] == t[j-1]){
                    currentRow[j] += previousRow[j-1];
                }
            }
            previousRow = currentRow;
        }
        return (int)previousRow[m];
    }
};