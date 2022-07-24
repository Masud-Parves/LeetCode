class Solution {
private:
    bool binarySearch(vector<vector<int>>& matrix, int target, int start, bool isVertical){
        int rows = matrix.size(), cols = matrix[0].size();
        
        int lo = start, hi = isVertical == true ? cols-1 : rows-1;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isVertical){
                if(matrix[start][mid] == target){
                    return true;
                }
                if(matrix[start][mid]<target){
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            } else {
                if(matrix[mid][start] == target){
                    return true;
                }
                if(matrix[mid][start]<target){
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        int minDiagonal = min(rows, cols);
        for(int i=0; i<minDiagonal ; i++){
            
            bool vertical = binarySearch(matrix, target, i, true);
            bool horizontal = binarySearch(matrix, target, i, false);
            
            if(vertical || horizontal){
                return true;
            }
            
        }
        
        return false;
    }
};