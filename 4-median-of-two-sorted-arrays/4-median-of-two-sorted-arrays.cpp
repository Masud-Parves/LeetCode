class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        vector<int> mergedArray;
        
        int i=0, j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                mergedArray.push_back(nums1[i++]);
            } else {
                mergedArray.push_back(nums2[j++]);
            }
        }
        
        while(i<n) mergedArray.push_back(nums1[i++]);
        while(j<m) mergedArray.push_back(nums2[j++]);
        
        int pivot = (m+n)/2;
        if((m+n)%2 == 1){
            return mergedArray[pivot];
        } 
        return (mergedArray[pivot] + mergedArray[pivot-1])/2.0;
    }
};