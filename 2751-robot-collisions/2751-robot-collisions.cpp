#define pb push_back
#define srt(v) sort(v.begin(),v.end())
#define ff first
#define ss second

//type definitions

typedef long long ll;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,pair<int, char> >> robots;
        int n=positions.size();
        for(int i=0;i<n;i++){
            robots.push_back({positions[i],{healths[i], directions[i]}});
        }
        srt(robots);
        
        string dir="";
        
        vector<int> positions1(n), healths1(n);
        
        for(int i=0;i<n;i++){
            positions1[i]=robots[i].ff;
            healths1[i]=(robots[i].ss).ff;
            dir+=(robots[i].ss).ss;
        }
        
        // directions=dir;
        
        vector<int> ans;
        map<int,int> sur;
        stack<pair<int,int> >s;
        for(int i=0;i<n;i++){
            if(dir[i]=='L'){
                int cur=healths1[i];
                while(cur>0 && s.size()>0){
                    pair<int,int> t=s.top();
                    s.pop();
                    if(t.ss==cur){
                        cur=0;
                        continue;
                    }
                    else if(t.ss>cur){
                        cur=0;
                        s.push({t.ff,t.ss-1});
                    }
                    else{
                        cur--;
                    }
                }
                if(cur>0){
                    sur[positions1[i]]=cur;
                }
            }
            else{
                s.push({positions1[i], healths1[i]});
            }
        }
        
        while(s.size()>0){
            pair<int,int> t=s.top();
            sur[t.ff]=t.ss;
            s.pop();
        }
        
        for(int i=0;i<n;i++){
            if(sur[positions[i]]!=0){
                ans.push_back(sur[positions[i]]);
            }
        }
        
        return ans;
        
    }
};