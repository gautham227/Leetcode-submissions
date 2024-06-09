class Solution {
public:
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        multiset<int> ms;
        int ans=0;
        int ind=0;
        int n=events.size();
        for(int day=1;day<=100000;day++){
            while(ind<n && events[ind][0]==day){
                ms.insert(events[ind][1]);
                ind++;
            }
            if(ms.size()>0){
                ans++;
                ms.erase(ms.begin());
            }
            while(ms.size()>0 && (*(ms.begin()))==day){
                ms.erase(ms.begin());
            }
        }
        return ans;
    }
};