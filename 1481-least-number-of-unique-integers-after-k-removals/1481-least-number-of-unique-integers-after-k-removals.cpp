class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int> cur;
        for(auto ele: mp){
            cur.push_back(ele.second);
        }
        sort(cur.begin(), cur.end());
        int cnt=0;
        while(k>0){
            int x=min(k,cur[cnt]);
            k-=x;
            cur[cnt]-=x;
            if(cur[cnt]==0)cnt++;
        }
        return cur.size()-cnt;
    }
};