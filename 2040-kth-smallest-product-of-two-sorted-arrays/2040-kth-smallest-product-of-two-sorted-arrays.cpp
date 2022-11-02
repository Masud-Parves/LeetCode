class Solution {
private:
    long long countMinimumNumber(vector<int>& nums1, vector<int>& nums2, long long product){
        long long count = 0LL;
        
        for(auto& val : nums1){
            if(val >=0){
                int left = 0, right = nums2.size(), mid;
                
                while(left < right){
                    mid = (left+right)/2;
                    if(val*1LL*nums2[mid] < product) {
                        left = mid+1;
                    } else {
                        right = mid;
                    }
                }
                
                count += left*1LL;
            } else {
                int left = 0, right = nums2.size(), mid;
                
                while(left < right){
                    mid = (left+right)/2;
                    if(val*1LL*nums2[mid] >= product) {
                        left = mid+1;
                    } else {
                        right = mid;
                    }
                }
                count += (nums2.size()-left)*1LL;
            }
        }
        return count;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long lb = (long long) -1e10, rb = (long long) 1e10, product;
        
        while(lb <= rb){
            product = (lb+rb)/2;
            if(countMinimumNumber(nums1, nums2, product) < k){
                lb = product+1;
            } else {
                rb = product-1;
            }
        }
        return rb;
    }
};