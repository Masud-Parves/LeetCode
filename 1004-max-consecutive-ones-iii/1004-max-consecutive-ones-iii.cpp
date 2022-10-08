class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> seen;
        
        int l = 0, currMax = 0;
        
        for(int r=0; r<n; r++){
            if(arr[r]==0){
                seen[arr[r]]++;
                if(seen[arr[r]]>k){
                    while(seen[arr[r]]>k) {
                        seen[arr[l]]--;
                        l++;
                    }
                }
            }
            if(r-l+1>currMax){
                currMax = max(currMax, r-l+1);
            }
        }
        return currMax;
    }
};