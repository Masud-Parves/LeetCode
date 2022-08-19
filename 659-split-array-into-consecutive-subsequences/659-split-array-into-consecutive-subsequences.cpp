class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> seen, next;
        
        for(auto& num : nums){
            seen[num]++;
        }
        
        for(auto& num : nums){
            if(seen[num] == 0) continue;
            seen[num]--;
            
            if(next[num-1]>0){
                    next[num]++;
                    next[num-1]--;
            } else if(seen[num+1]>0 && seen[num+2]>0){
                seen[num+1]--;
                seen[num+2]--;
                next[num+2]++;
            } else return false;
      
        }
        return true;
    }
};