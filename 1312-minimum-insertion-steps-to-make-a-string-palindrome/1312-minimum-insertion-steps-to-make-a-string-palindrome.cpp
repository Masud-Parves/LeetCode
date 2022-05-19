class Solution {
public:
    int LPS(string& s1, string& s2){
        int n = s1.size();
        vector<int> previousRow(n+1, 0);
        vector<int> currentRow(n+1, 0);
        
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=n ; j++){
                if(s1[i-1] == s2[j-1]){
                    currentRow[j] = 1 + previousRow[j-1];
                } else {
                    currentRow[j] = max(previousRow[j], currentRow[j-1]);
                }
            }
            previousRow = currentRow;
        }
        
        return previousRow[n];
        
    }
    
    
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s.size() - LPS(s, t);
    }
};