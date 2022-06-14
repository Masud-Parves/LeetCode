// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // aaabbbbbbb
        int len = s.size();
        
        string result = "";
        
        for(int i=0; i<len ; i++){
            if(i == 0 || s[i] != result.back()) {
                result += s[i];
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends