class Solution {
private:
    vector<int> usingExtraSpace(vector<int>& nums){
        int n = nums.size();
        vector<int>answer(n, 1);
        vector<int>left(n, 1), right(n, 1);
        
        for(int i=1; i<n; i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        
        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        
        for(int i=0; i<n; i++){
            answer[i] = left[i]*right[i];
        }
        return answer;
    }
    
    vector<int> usingNoExtraSpace(vector<int>& nums){
        int n = nums.size();
        vector<int>answer(n, 1);
        
        for(int i=1; i<n; i++) {
            answer[i] = answer[i-1]*nums[i-1];
        }
        int R = 1;
        for(int i=n-1; i>=0; i--){
            answer[i] *= R;
            R *= nums[i];
        }
        return answer;
    }
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        return usingNoExtraSpace(nums);
    }
};