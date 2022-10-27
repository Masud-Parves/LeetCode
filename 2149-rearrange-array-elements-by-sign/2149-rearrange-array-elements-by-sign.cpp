class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer;
        int n = nums.size();
        
        vector<int> positive, negative;
        for(auto& val : nums){
            if(val<0){
                negative.push_back(val);
            } else {
                positive.push_back(val);
            }
        }
        
        int i=0;
        int posIdx = 0, negIdx = 0;
        while(i<n){
            if(i&1){
                answer.push_back(negative[negIdx]);
                negIdx++;
            } else {
                answer.push_back(positive[posIdx]);
                posIdx++;
            }
            i++;
        }
        return answer;
    }
};