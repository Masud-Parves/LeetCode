class Solution {
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        
        sort(arr.begin(), arr.end(), [x](const auto& a, const auto& b){
            if(abs(x-a) == abs(x-b)) return a<b;
            return abs(x-a) < abs(x-b);
        });
        
        result = vector<int>(arr.begin(), arr.begin()+k);
        sort(result.begin(), result.end());
        return result;
    }
};