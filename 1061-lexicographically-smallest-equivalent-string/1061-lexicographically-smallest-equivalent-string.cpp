class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,set<char> >mp;
        for(int i=0;i<26;i++){
            mp[(char)('a'+i)].insert((char)('a'+i));
        }
        int n=s1.size();
        for(int i=0;i<n;i++){
            mp[s1[i]].insert(s2[i]);
            mp[s2[i]].insert(s1[i]);
        }
        
        for(int i=0;i<26;i++){
            queue<char> q;
            for(auto ele: mp[(char)('a'+i)]){
                if(ele==(char)('a'+i))continue;
                q.push(ele);
            }
            while(!q.empty()){
                char cur=q.front();
                q.pop();
                for(auto ele: mp[cur]){
                    if(mp[(char)('a'+i)].find(ele)!=mp[(char)('a'+i)].end()){
                        continue;
                    }
                    mp[(char)('a'+i)].insert(ele);
                    q.push(ele);
                }
            }
        }
        
        string ans="";
        
        for(int i=0;i<baseStr.size();i++){
            ans.push_back((*(mp[baseStr[i]]).begin()));
        }
        
        return ans;
    }
};