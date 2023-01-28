class SummaryRanges {
public:
    vector<int> v;
    SummaryRanges() {
        for(int i=0;i<=1e4;i++){
            v.push_back(0);
        }
    }
    
    void addNum(int value) {
        v[value]=1;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int> >ans;
        int st=-1, en=-1;
        for(int i=0;i<=1e4;i++){
            if(v[i]==1){
                if(st==-1)st=i;
                en=i;
            }
            else{
                if(st!=-1)ans.push_back({st,en});
                st=-1;
                en=-1;
            }
        }
        if(st!=-1)ans.push_back({st,en});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */