class Solution {
public:
    
    set<string> ans;
    
    void recur(string& s, string& cur, int ind, int used, int muse, int len, int num, int type){
        // cout<<ind<<" "<<num<<endl;
        if(num>255 || ind>len)return;
        if(used>muse)return;
        if(ind==len){
            if(used==muse && num<=255)ans.insert(cur);
            return;
        }
        if((num*10+(s[ind]-'0')<=255 && type==0) && (ind!=0 || s[ind]!='0')){
            cur.push_back(s[ind]);
            recur(s,cur,ind+1,used,muse,len,num*10+(s[ind]-'0'),0);
            cur.pop_back();
        }
        if(ind!=0 || type==1){
            cur.push_back('.');
            cur.push_back(s[ind]);
            if(s[ind]!='0' || ind==len-1)recur(s,cur,ind+1,used+1,muse,len,s[ind]-'0',0);
            else{
            //     int cnt=0;
            //     while(ind+1+cnt<len && s[ind+cnt+1]=='0'){
            //         cur.push_back('.');
            //         cur.push_back(s[ind+cnt+1]);
            //         // recur(s,cur,ind+2,used+2,muse,len,s[ind+1]-'0');
            //         // cur.pop_back();
            //         // cur.pop_back();
            //         cnt++;
            //     }
            //     if(used+cnt+1>muse)return;
            //     if(ind+cnt+1<len){
            //         cur.push_back('.');
            //         cur.push_back(s[ind+cnt+1]);
            //         recur(s,cur,ind+cnt+2,used+cnt+2,muse,len,s[ind+cnt+1]-'0',0)   ;
            //         cur.pop_back();
            //         cur.pop_back();
            //     }
            //     while(cnt--){
            //         cur.pop_back();
            //         cur.pop_back();
            //     }
                recur(s,cur,ind+1,used+1,muse,len,0,1);
            }  
            cur.pop_back();
            cur.pop_back(); 
        }
        if(ind==0 && s[ind]=='0'){
            cur.push_back(s[ind]);
            recur(s,cur,ind+1,used,muse,len,0,1);
            cur.pop_back();
        }
        return;
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> ans1;
        string cur="";
        recur(s,cur,0,0,3,s.size(),0,0);
        
        for(auto str: ans)ans1.push_back(str);
        
        return ans1;
        
    }
};