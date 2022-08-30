class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int totalGas = 0, totalCost = 0;
        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalGas<totalCost) return -1;
        int total = 0, pickStation = 0;
        for(int i=0; i<n; i++){
            total += gas[i]-cost[i];
            if(total<0){
                total = 0;
                pickStation = i+1;
            }
            
        }
        return pickStation;
    }
};