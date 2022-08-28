class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>>pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto& num : nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>K) {
            pq.pop();
        }
        return pq.top();
    }
};

