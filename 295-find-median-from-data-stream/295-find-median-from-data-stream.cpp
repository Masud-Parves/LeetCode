class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>>higher;
    priority_queue<int>lower;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower.empty()){
            lower.push(num);
            return;
        }

        if(lower.size()>higher.size()){
            if(lower.top()>num){
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            } else {
                higher.push(num);
            }
        } else {
            if(higher.top()<num){
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            } else {
                lower.push(num);
            }
        }
        return;
    }
    
    double findMedian() {
        double result = 0.0;
        if (lower.size() == higher.size()) {
            result =  lower.top() + (higher.top() - lower.top()) / 2.0;
        } else {
            if (lower.size() > higher.size()) {
                result = lower.top();
            } else {
                result = higher.top();
            }
        }
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */