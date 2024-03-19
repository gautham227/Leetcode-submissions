class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        set<pair<int, char> >s;
        vector<int> cnt(26,0);
        for(int i=0;i<tasks.size();i++){
            cnt[tasks[i]-'A']++;
        }
        // for(auto ele: cnt){
        //     cout<<ele<<" ";
        // }
        // cout<<endl;
        int tot=tasks.size();
        set<char> used;
        int ans=0;
        while(tot>0){
            // cout<<tot<<endl;
            // for(auto ele: cnt){
            //     cout<<ele<<" ";
            // }
            // cout<<endl;
            while(s.size()>0 && (*s.begin()).first<=ans-n){
                used.erase(used.find((*s.begin()).second));
                s.erase(s.find(*s.begin()));
            }
            int macnt=0;
            char x='A';
            for(int i=0;i<26;i++){
                if(cnt[i]>macnt && used.find((char)('A'+i))==used.end()){
                    macnt=cnt[i];
                    x=(char)('A'+i);
                }
            }
            ans++;
            if(macnt!=0){
                tot--;
                s.insert({ans,x});
                used.insert(x);
                cnt[x-'A']--;
            }
        }
        return ans;
    }
};