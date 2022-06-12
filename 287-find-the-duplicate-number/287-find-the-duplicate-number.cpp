class Solution {
private:
    int usingMissingTechnique(vector<int>& nums){
        int n = nums.size();
        
        int duplicate = -1;
        for(int i=0; i<n; i++){
            int cur = abs(nums[i]);
            if(nums[cur] < 0){
                duplicate = cur;
                break;
            }
            nums[cur] *=-1;
        }
        
        for(auto num : nums){
            num = abs(num);
        }
        return duplicate;
    }
    
    int usingSortTechnique(vector<int> nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }
    
    int usingHashMap(vector<int>& nums){
        int n = nums.size();
        unordered_map<int, int>seen;
        
        for(int i=0; i<n; i++){
            if(seen.find(nums[i])!=seen.end()){
                return nums[i];
            }
            seen[nums[i]] = i+1;
        }
        return -1;
    }
    
public:
    int findDuplicate(vector<int>& nums) {
        return usingHashMap(nums);
    }
};