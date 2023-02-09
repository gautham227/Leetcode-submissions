class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<set<string> >v(26);
        for(int i=0;i<ideas.size();i++){
            v[ideas[i][0]-'a'].insert(ideas[i].substr(1,ideas.size()-1));
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long long cnt=0;
                for(auto ele: v[i]){
                    if(v[j].find(ele)!=v[j].end())cnt++;
                }
                ans+=(v[i].size()-cnt)*(v[j].size()-cnt);
            }
        }
        return ans*2;
    }
};