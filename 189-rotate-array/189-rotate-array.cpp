class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int start=0; count<n; start++){
            
            int currIdx = start;
            int currEle = nums[start];
            
            do{
                int tmpIdx = (currIdx + k)%n;
                int tmpEle = nums[tmpIdx];
                nums[tmpIdx] = currEle;
                currIdx = tmpIdx;
                currEle = tmpEle;
                count++;
                
            } while(start != currIdx);
            
            
            
        }
        return;
        
    }
};