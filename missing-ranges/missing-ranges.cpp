class Solution {
private:
    string make_format(int lower, int upper){
        string curr = "";
        if(lower == upper){
            curr = to_string(lower);
        } else {
            curr = to_string(lower) + "->" + to_string(upper);
        }
        return curr;
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        
        int lo, hi, curr, prev = lower-1;
        
        for(int i=0; i<= nums.size(); i++){
            curr = (i<nums.size()) ? nums[i] : upper+1;

            if(prev+1 <= curr-1){
                string str = make_format(prev+1, curr-1);
                result.push_back(str);
            }
            
            prev = curr;
        }
        
        
        
        return result;
    }
};