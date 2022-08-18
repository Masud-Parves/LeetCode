class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int>previousRow(m, 0), currentRow(m, 0);

        for(int idx1=0; idx1<n; idx1++){
        	for(int idx2 = 0; idx2<m; idx2++){
        		int way1 = 0, way2 = 0;
        		if(text1[idx1] == text2[idx2]){
        			way1 = 1;
        			if(idx1-1>=0 && idx2-1>=0){
        				way1 += previousRow[idx2-1];
        			} 
        		} else {
        			if(idx1-1>=0) way2 = previousRow[idx2];
        			if(idx2-1>=0) way2 = max(way2, currentRow[idx2-1]);
        		}
                currentRow[idx2] = max(way1, way2);
        	}
        	previousRow = currentRow;
        }
        return previousRow[m-1];
    }
};