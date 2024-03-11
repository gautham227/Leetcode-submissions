class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n=arr.size();
        vector<unordered_set<string> >v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<arr[i].size();j++){
                string str="";
                for(int k=j;k<arr[i].size();k++){
                    str.push_back(arr[i][k]);
                    v[i].insert(str);
                }
            }
        }
        
        vector<string> ans(n,"");
        
        for(int i=0;i<n;i++){
            string cur="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
            for(auto &ele: v[i]){
                bool flag=false;
                for(int j=0;j<n;j++){
                    if(i==j)continue;
                    if(v[j].find(ele)!=v[j].end()){
                        flag=true;
                    }
                }
                if(!flag){
                    if(ele.size()<cur.size()){
                        cur=ele;
                    }
                    else if(ele.size()==cur.size()){
                        if(ele<cur)cur=ele;
                    }   
                }
            }
            if(cur!="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz")ans[i]=cur;
        }
        
        return ans;
    }
};