class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , vector<string> >mp;
        
        for(auto &st: strs){
            vector<int> cnt(26,0);
            
            for(int i=0;i<st.size();i++){
                cnt[st[i]-'a']++;
            }
            
            mp[cnt].push_back(st);
        }
        
        vector<vector<string> >ans;
        
        for(auto ele: mp){
            ans.push_back(ele.second);
        }
        
        return ans;
    }
};