class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> result;
        if(n<=1 ||  n&1) return result;
        
        unordered_map<int, int> seen;
        for(auto& num : changed){
            seen[num]++;
        }
        
        sort(changed.begin(), changed.end());
        for(int num : changed){
            if(seen[num] and seen[num*2]){
                if(num == num*2 && seen[num]<=1){
                    result.clear();
                    return result;
                }
                result.push_back(num);
                seen[num]--;
                seen[num*2]--;
            }
            
        }

        return result.size() != n/2 ? vector<int>() : result;
    }
};