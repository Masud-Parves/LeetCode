class Solution {
private:
    int helper(vector<vector<int>>& matrix, int mid){
        int n = matrix.size();
        int i = matrix.size()-1, j = 0;
        int count = 0;
        while(i>=0 && j<n){
            if(matrix[i][j]>mid){
                i--;
            } else {
                count += (i+1);
                j++;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int left = matrix[0][0], right = matrix[row-1][col-1], mid;
        
        while(left<right){
            mid = left + (right-left)/2;
            int count = helper(matrix, mid);
            if(count<k){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};