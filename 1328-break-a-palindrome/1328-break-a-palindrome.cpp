class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        
        int firstIdx = -1;
        bool okay = false;
        for(int i=0; i<n; i++){
            if(firstIdx==-1 && palindrome[i] != 'a'){
                firstIdx = i;
            } else if(palindrome[i] != 'a'){
                okay = true;
                break;
            }
        }
        
        if(okay){
            palindrome[firstIdx] = 'a';
            return palindrome;
        }
        
        for(int i=n-1; i>=0; i--){
            if(palindrome[i]!='b'){
                palindrome[i] = 'b';
                return palindrome;
            }
        }
        return "";
    }
};