class Solution {
private:
    int helper(int idx, vector<int>& one, vector<int>& zero, int numOfOne, int numOfZero,
              vector<vector<vector<int>>>& cache){
        if(idx == one.size()){
            return 0;
        }
        int& currState = cache[idx][numOfOne][numOfZero];
        if(currState != -1){
            return currState;
        }
        
        int way1 = 0, way2 = 0;
        way1 = helper(idx+1, one, zero, numOfOne, numOfZero, cache);
        if(numOfOne>=one[idx] && numOfZero>=zero[idx]){
            way2 = 1 + helper(idx+1, one, zero, numOfOne-one[idx], numOfZero-zero[idx], cache);
        }
        return currState = max(way1 , way2);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<int>one, zero;
        for(auto& str : strs){
            int countOne = 0, countZero = 0;
            for(auto& c : str){
                if(c == '1') countOne++;
                else countZero++;
            }
            one.push_back(countOne);
            zero.push_back(countZero);
        }
        vector<vector<vector<int>>> cache(len, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        int ret = helper(0, one, zero, n, m, cache);
        return ret;
    }
};