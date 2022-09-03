class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> seen;
        for(int i=0; i<arr.size(); i++){
            seen[arr[i]] = i;
        }
        
        int maxRight = 0, result = 0;
        for(int r=0; r<arr.size(); r++){
            maxRight = max(maxRight, seen[r]);
            if(r == maxRight){
                result++;
            }
        }
        return result;
    }
};