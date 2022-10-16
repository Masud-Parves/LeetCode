class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        if(n<2) return 0;
        int result = 0;
        int currVal = 0, prevVal = 0;
        
        int same = 0, prevSame = 0;
        for(int i=0; i+1<n; i++){
            same++;
            if(s[i]!=s[i+1]){
                result += min(prevSame, same);
                prevSame = same;
                same = 0;
            }
        }
        if(s[n-2] == s[n-1]){
            same++;
            result += min(prevSame, same);
        } else result+=1;
        return result;
    }
};