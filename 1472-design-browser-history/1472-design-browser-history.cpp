class BrowserHistory {
public:
    
    vector<string> v;
    int cur=-1;
    int len=0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        cur=0;
        len=1;
    }
    
    void visit(string url) {
        if(cur+1==v.size()){
            v.push_back(url);
            len=v.size();
        }
        else{
            v[cur+1]=url;
            len=cur+2;
        }
        cur++;
    }
    
    string back(int steps) {
        if(cur>=steps){
            cur-=steps;
        }
        else{
            cur=0;
        }
        return v[cur];
    }
    
    string forward(int steps) {
        if(steps>len-cur-1){
            cur=len-1;
        }
        else{
            cur+=steps;
        }
        return v[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */