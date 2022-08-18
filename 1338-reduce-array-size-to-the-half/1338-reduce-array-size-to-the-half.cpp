class Solution {
public:
    int minSetSize(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> seen;
        
        for(auto& num : nums){
            seen[num]++;
        }
        
        priority_queue<int>q;
        for(auto& m : seen){
            q.push(m.second);
            
        }
        
        int removed = 0, ret = 0;
        while(removed<n/2){
            int r = q.top();
            q.pop();
            ret++;
            removed += r;
        }
        return ret;
    }
};