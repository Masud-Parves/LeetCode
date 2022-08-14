class Solution {
public:
    bool isSubsequence(string t, string s) {
        int n = s.size(), m = t.size();
        int idxS = 0, idxT = 0;
        while(idxS<n && idxT<m){
            if(s[idxS] == t[idxT]){
                idxS++;
                idxT++;
            } else {
                idxS++;
            }
        }
        return idxT == m;
    }
};