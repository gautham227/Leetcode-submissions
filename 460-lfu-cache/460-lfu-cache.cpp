class LFUCache {
public:
    int mcap;
    set<vector<int> >s;
    map<int,int> freq;
    map<int,int> last;
    map<int,int> val;
    int ind;
    LFUCache(int capacity) {
        mcap=capacity;
        ind=0;
    }
    
    int get(int key) {
        ind++;
        if(freq.find(key)!=freq.end()){
            s.erase(s.find({freq[key], last[key], key}));
            freq[key]++;
            last[key]=ind;
            s.insert({freq[key], last[key], key});
            return val[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        ind++;
        if(freq.find(key)!=freq.end()){
            s.erase(s.find({freq[key], last[key], key}));
            freq[key]++;
            last[key]=ind;
            s.insert({freq[key], last[key], key});
            val[key]=value;
            return;
        }
        else if(s.size()<mcap){
            freq[key]++;
            last[key]=ind;
            val[key]=value;
            s.insert({freq[key], last[key], key});
            return;
        }
        else{
            if(mcap==0)return;
            vector<int> v1=*(s.begin());
            int k=v1[2];
            freq.erase(freq.find(k));
            last.erase(last.find(k));
            val.erase(val.find(k));
            s.erase(s.begin());
            freq[key]++;
            last[key]=ind;
            val[key]=value;
            s.insert({freq[key], last[key], key});
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */