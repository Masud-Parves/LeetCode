class StockSpanner {
private:
    stack<pair<int, int>> st;
    int idx;
public:
    StockSpanner() {
        while(!st.empty()){
            st.pop();
        }
        idx = 0;
    }
    
    int next(int price) {
        
        int ret = 0;
        if(st.empty()){
            ret = idx+1;
        } else if(!st.empty() && st.top().first>price) {
            ret = idx - st.top().second;
        } else {
            while(!st.empty() && st.top().first<=price){
                st.pop();
            }
            //cout << idx << " " << st.empty() << endl;
            if(st.empty()){
                cout << price << " " << idx << endl;
                ret = idx+1;
            } else {
                ret = idx - st.top().second;
            }
        }
        
        st.push({price, idx});
        idx++;
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */