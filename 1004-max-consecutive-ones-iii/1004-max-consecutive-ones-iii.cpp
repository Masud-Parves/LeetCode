class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        
        int l = 0, currMax = 0;
        int countZero = 0;
        for(int r=0; r<n; r++){
            if(arr[r]==0){
                countZero++;
                while(countZero>k) {
                    if(arr[l]==0)
                        countZero--;
                    l++;
                }

            }
            if(r-l+1>currMax){
                currMax = max(currMax, r-l+1);
            }
        }
        return currMax;
    }
};