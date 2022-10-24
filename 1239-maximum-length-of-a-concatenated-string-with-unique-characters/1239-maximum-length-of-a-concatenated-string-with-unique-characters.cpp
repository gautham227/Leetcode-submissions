class Solution {
public:
    
    int recur(int ind, vector<int>& cur, int carry){
        if(ind==cur.size()){
            return 0;
        }
        if((carry&cur[ind])==0){
            return max(recur(ind+1,cur,carry),recur(ind+1,cur,carry|cur[ind])+__builtin_popcount(cur[ind]));
        }
        return recur(ind+1,cur,carry);
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int cur=0;
            bool flag=true;
            for(int j=0;j<arr[i].size();j++){
                if((cur&(1<<(arr[i][j]-'a'))) ==0){
                    cur|=(1<<(arr[i][j]-'a'));
                }
                else{
                    flag=false;
                }
            }
            if(flag)v.push_back(cur);
        }
        return recur(0,v,0);
    }
};