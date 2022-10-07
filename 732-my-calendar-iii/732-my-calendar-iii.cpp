class MyCalendarThree {
private:
    map<int, int> seen;
    int maxMeeting;
public:
    
    MyCalendarThree() {
        seen.clear();
        maxMeeting = 0;
    }
    
    int book(int start, int end) {
        seen[start]++;
        seen[end]--;
        int currMeeting = 0;
        for(auto& m : seen){
            currMeeting += m.second;
            maxMeeting = max(maxMeeting, currMeeting);
        }
        return maxMeeting;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */