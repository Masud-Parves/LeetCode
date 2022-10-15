
class comparator{
    public : 
        int operator()(pair<int,int> &c1,pair<int,int> &c2){
    
            double old_c1 = c1.first*1.0/c1.second*1.0;
            double new_c1 = (c1.first+1)*1.0/(c1.second+1)*1.0;

            double old_c2 = c2.first*1.0/c2.second*1.0;
            double new_c2 = (c2.first+1)*1.0/(c2.second+1)*1.0;

            double avgDiffC1 = new_c1 - old_c1;
            double avgDiffC2 = new_c2 - old_c2;

            return avgDiffC1 <= avgDiffC2;
    
        }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int numOfClass = classes.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> todo;
        int wellClasses = 0;
        for(auto& eachClass : classes){
            if(eachClass[0] != eachClass[1]){
                todo.push({eachClass[0], eachClass[1]});
            } else wellClasses++;
        }
        
        while(extraStudents>0 && !todo.empty()){
            auto weakestClass = todo.top();
            todo.pop();
            weakestClass.first++, weakestClass.second++;
            todo.push(weakestClass);
            extraStudents--;
        }
        double totalPassAvg = 0.0;
        while(!todo.empty()){
            int pass = todo.top().first;
            int total = todo.top().second;
            todo.pop();
            totalPassAvg += (double)(pass*1.0/total*1.0);
        }
        
        totalPassAvg += wellClasses*1.0;
        return totalPassAvg/numOfClass;
    }
};