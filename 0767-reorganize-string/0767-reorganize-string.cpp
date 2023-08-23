class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        int n=s.size();
        string ans = "";
        for(int i=0;i<n;i++){
            ans.push_back('1');
            mp[s[i]]++;
        }
        vector<vector<int> >cur;
        for(auto ele: mp){
            cur.push_back({ele.second, ele.first-'a'});
        }
        sort(cur.begin(), cur.end());
        reverse(cur.begin(), cur.end());
        
        int ind=0;
        for(auto ele: cur){
            char x=(char)('a'+ele[1]);
            int cnt=ele[0];
            while(cnt--){
                ans[ind]=x;
                ind+=2;
                if(ind>n-1){
                    ind=1;
                }
            }
        }
        bool flag=true;
        for(int i=1;i<n;i++){
            if(ans[i]==ans[i-1]){
                flag=false;
                break;
            }
        }
        if(!flag)return "";
        return ans;
    }
};