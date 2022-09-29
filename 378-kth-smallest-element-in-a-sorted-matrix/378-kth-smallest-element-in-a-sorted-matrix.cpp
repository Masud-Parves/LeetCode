class Solution {
private:
    int helper(int target, vector<vector<int>>& matrix){
        int n = matrix.size();
        int row = 0, col = n-1;
        int count = 0;
        while(row<n && col>=0){
            if(matrix[row][col]<=target){
                count += col+1;
                row++;
            } else {
                col--;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1], mid;
        
        while(low<high){
            mid = low + (high-low)/2;
            if(helper(mid, matrix)<k){
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};