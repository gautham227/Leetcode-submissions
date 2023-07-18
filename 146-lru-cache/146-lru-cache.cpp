class LRUCache {
public:
    int cap;
    map<int,int> mp;
    map<int,int> lastused;
    set<vector<int> > s;
    int counter;
    LRUCache(int capacity) {
        cap=capacity;
        counter=0;;
        cout<<cap<<" "<<counter<<endl;
    }
    
    int get(int key) {
        // cout<<key<<endl;
        if(mp.find(key)!=mp.end()){
            s.erase(s.find({lastused[key], key}));
            lastused[key]=counter;
            counter++;
            s.insert({lastused[key], key});
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        // cout<<key<<" "<<value<<endl;
        if(mp.find(key)!=mp.end()){
            mp[key]=value;
            s.erase(s.find({lastused[key], key}));
            lastused[key]=counter;
            s.insert({lastused[key], key});
        }
        else if(mp.size()<cap){
            mp[key]=value;
            lastused[key]=counter;
            s.insert({lastused[key], key});
        }
        else{
            // cout<<"begin"<<endl;
            int val;
            for(auto ele: s){
                val=ele[1];
                break;
            }
            
            mp.erase(val);
            lastused.erase(key);
            // cout<<1234<<endl;
            s.erase(s.begin());
            // cout<<12345<<endl;
            mp[key]=value;
            lastused[key]=counter;
            s.insert({lastused[key], key});
        }
        counter++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */