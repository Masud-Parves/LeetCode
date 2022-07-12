// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        
        string longestPali = "";
        int longest = 0;
        
        int n = s.size();
        
        for(int i=0; i<n; i++){
            int L = i, R = i;
            while(L>=0 && R<n && s[L] == s[R]){
                L--;
                R++;
            }
            L++;
            R--;
            int len = R-L+1;
            if(len > longest){
                longest = len;
                longestPali = s.substr(L, R-L+1);
            }
            
            if(i+1<n){
                L = i, R = i+1;
                while(L>=0 && R<n && s[L] == s[R]){
                    L--;
                    R++;
                }
                L++;
                R--;
                len = R-L+1;
                if(len > longest){
                    longest = len;
                    longestPali = s.substr(L, R-L+1);
                }
            }
            
            
            
        }
        return longestPali;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends