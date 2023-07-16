class Solution {
public:
    long long mval;
    long long recur(long long ind, long long req , vector<vector<string> >& ppl, map<string,long long>& skills, vector<vector<long long> >& dp){
        // cout<<req<<endl;
        if(req==0)return 0; 
        if(ind<0){
            return mval;
        }
        if(dp[req][ind]!=-1)return dp[req][ind];
        long long needs = req;
        for(auto ele: ppl[ind]){
            needs = needs & (~ (1<<(1ll*skills[ele])));
        }
        
        
        long long curans = recur(ind-1, req, ppl, skills, dp);
        long long newans = (1*1ll<<(ind*1ll)) | (recur(ind-1, needs, ppl, skills, dp));
        
        if(__builtin_popcountll(curans)< __builtin_popcountll(newans)){
            dp[req][ind]=curans;
        }
        else{
            dp[req][ind]=newans;
        }
        
        return dp[req][ind];
        
    }
    
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<vector<long long> >dp((1<<16)+1, vector<long long>(60,-1));
        map<string,long long> mp;
        int cnt=0;
        long long req=0;
        for(int i=0;i<req_skills.size();i++){
            mp[req_skills[i]]=cnt*1ll;
            req = req | (1*1ll<<cnt);
            // cout<<req<<endl;
            cnt++;
        }
        
        mval=req;
        
        long long ret = recur(people.size()-1, req, people, mp, dp);
        
        vector<int> ans;
        
        for(long long  i=0;i<=60;i++){
            if((1ll*ret>>i)&1)ans.push_back(i);
        }
        
        return ans;
        
        
    }
};