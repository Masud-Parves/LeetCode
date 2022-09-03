class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto& stick : sticks){
            pq.push(stick);    
        }
        int minCost = 0;
        while(pq.size()>1){
            int minVal = pq.top();
            pq.pop();
            int secMinVal = pq.top();
            pq.pop();
            
            minCost += minVal + secMinVal;
            pq.push(minVal + secMinVal);
        }
        return minCost;
    }
};