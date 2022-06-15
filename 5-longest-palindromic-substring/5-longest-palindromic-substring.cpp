class Solution {
private:
    string expended(int l, int r, string& s){
        int n = s.size();
        int low = l, high = r;
        
        while(low>=0 && high<n && s[low] == s[high]) {
            low--;
            high++;
        }
        return s.substr(low+1, high-low-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        string result = "";
        int longestPalin = 0;
        
        for(int i=0; i<n ; i++){
            // odd case 
            string res = expended(i, i, s);
            
            if(res.size() > longestPalin) {
                longestPalin = res.size();
                result = res;
            }
            // even case 
            
            if(i+1<n) {
                res = expended(i, i+1, s);
                if(res.size() > longestPalin) {
                    longestPalin = res.size();
                    result = res;
                }
            }
        }
        return result;
    }
};