class MyCalendar {
public:
    map<int, int> booked;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        end--;
        for(auto it: booked){
            if((it.first >= start && it.second <= end)
               || (end >= it.first && end <= it.second)
               || (start >= it.first && start <= it.second))
                return false;
        }
        booked.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */