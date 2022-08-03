class MyCalendar {
public:
    
    set<pair<int, int>>booking;
    
    MyCalendar() {
        booking.clear();
    }
    
    bool book(int start, int end) {
        auto it = booking.upper_bound({start, end});
        
        if(it != booking.end() && it->second<end){
            return false;
        }
        booking.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */