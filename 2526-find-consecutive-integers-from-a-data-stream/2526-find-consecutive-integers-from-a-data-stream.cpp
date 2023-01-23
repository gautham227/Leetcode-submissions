class DataStream {
public:
    int req=-1;
    int cnt=-1;
    int cur=0;
    DataStream(int value, int k) {
        req=value;
        cnt=k;
    }
    
    bool consec(int num) {
        if(num!=req){
            cur=0;
        }
        else{
            cur++;
        }
        return (cur>=cnt);
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */