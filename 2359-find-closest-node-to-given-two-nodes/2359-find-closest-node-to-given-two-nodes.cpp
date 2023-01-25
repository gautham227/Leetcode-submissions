class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> mp;
        unordered_set<int> s1,s2;
        int cnt=0;
        int cur=node1;
        while(s1.find(cur)==s1.end() && cur!=-1){
            s1.insert(cur);
            mp[cur]=cnt;
            cur=edges[cur];
            cnt++;
        }
        int ans=INT_MAX;
        int ans1=-1;
        cnt=0;
        cur=node2;
        while(s2.find(cur)==s2.end() && cur!=-1){
            s2.insert(cur);
            if(s1.find(cur)!=s1.end()){
                if(ans>max(mp[cur],cnt)){
                    ans=max(mp[cur],cnt);
                    ans1=cur;
                }
                else if(ans==max(mp[cur],cnt)){
                    ans1=min(ans1,cur);
                }
            }
            cur=edges[cur];
            cnt++;
        }
        
        
        return ans1;
    }
};