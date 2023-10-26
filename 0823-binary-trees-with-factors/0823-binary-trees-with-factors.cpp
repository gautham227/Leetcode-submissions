class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long ans=0;
        sort(arr.begin(), arr.end());
        unordered_map<int,long long> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    mp[arr[i]]=(mp[arr[i]] + mp[arr[j]]*mp[arr[i]/arr[j]])%(1000000007);
                }
            }
            ans+=mp[arr[i]];
            ans%=1000000007;
        }
        return ans;
    }
};