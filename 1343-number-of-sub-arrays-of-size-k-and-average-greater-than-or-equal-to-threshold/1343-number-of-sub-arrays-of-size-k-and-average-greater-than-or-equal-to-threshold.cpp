/*
[11,13,17,23,29,31,7,5,2,3]

[11,24,41,64,93,104,111,116,118,121]
3
5
*/


class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int l = 0;
        
        for(int i=1; i<n; i++){
            arr[i] = arr[i-1]+arr[i];
        }
        int segmentSum = 0, subArray = 0;
        for(int r=0; r<n; r++){
            segmentSum = arr[r];

            if(r<k-1) continue;
            l = r-k;
            if(l>=0){
                segmentSum -= arr[l];
            }
            if(threshold<=(segmentSum/k)){
                    subArray++;
            }
            

        }
        
        return subArray;
    }
};