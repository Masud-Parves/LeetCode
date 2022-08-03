class MyCalendar {
private:
    map<int, int> seen;
public:
    
    MyCalendar() {
        seen.clear();
    }
    
    bool book(int start, int end) {
        seen[start]++;
        seen[end]--;
        int sum = 0;
        
        for(auto& it : seen){
            sum += it.second;
            if(sum>1){
                seen[start]--;
                seen[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */