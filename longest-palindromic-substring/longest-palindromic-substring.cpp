class Solution {
    string substr(int L , int R, string& s){
        string ret = "";
        while(L<=R){
            ret += s[L];
            L++;
        }
        return ret;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        
        
        int longest = 0;
        string longestPali = "";
        
        
        for(int i=0; i<n; i++){
            
            
            int L = i, R = i;
            while(L>=0 && R<n && s[L] == s[R]){
                L--;
                R++;
            }
            
            L++;
            R--;
            string currPali = substr(L, R, s);
            if(currPali.size()>longest){
                longest = currPali.size();
                longestPali = currPali;
            }
            
            
            L = i, R = i+1;
            while(L>=0 && R<n && s[L] == s[R]){
                L--;
                R++;
            }
            
            L++;
            R--;
            currPali = substr(L, R, s);
            if(currPali.size()>longest){
                longest = currPali.size();
                longestPali = currPali;
            }
            
            
        }
        
        
        
        return longestPali;
        
    }
};