class Solution {
public:
    
    set<string> ans;
    
    void recur(string& s, string& cur, int ind, int used, int muse, int len, int num, int type){
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