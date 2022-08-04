class MyCalendar {
public:
    set<pair<int,int> >s;
    MyCalendar() {
        s.insert({0,(int)1e9+1});
    }
    
    bool book(int start, int end) {
        pair<int,int> p{start,1e9+10};
        auto it=upper_bound(s.begin(), s.end(), p);
        if(s.size()!=0 && it==(s.begin())){
            cout<<1<<endl;
            return false;
        }
        it--;
        if(s.size()==0 || it->first<=start && it->second>=end){
            int st1=it->first, en1=it->second;
            s.erase(it);
            s.insert({st1,start});
            s.insert({end,en1});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */