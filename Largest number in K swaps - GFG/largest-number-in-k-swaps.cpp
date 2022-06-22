// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    private:
    void getMaxValueKSwap(int idx, string str, int k, string& maxVal){
        if(k==0) {
            return;
        }
        int n = str.length();
        
        char maxChar = str[idx];
        for(int i=idx+1; i<n; i++){
            if(maxChar < str[i]){
                maxChar = str[i];
            }
        }
        
        if(maxChar != str[idx]) --k;
        
        for(int i=n-1; i>=idx; i--){
            if(maxChar==str[i]){
                swap(str[idx], str[i]);
                
                if(str.compare(maxVal)>0){
                    maxVal = str;
                }
                getMaxValueKSwap(idx+1, str, k, maxVal);
                swap(str[idx], str[i]);
            }
        }
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string maxVal = str;
       getMaxValueKSwap(0, str, k, maxVal);
       return maxVal;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends