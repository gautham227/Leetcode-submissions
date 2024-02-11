class Solution {
public:
    
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string cur;
        for(auto ele: pattern){
            if(ele==1)cur.push_back('a');
            if(ele==0)cur.push_back('b');
            if(ele==-1)cur.push_back('c');
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])cur.push_back('a');
            if(nums[i]==nums[i-1])cur.push_back('b');
            if(nums[i]<nums[i-1])cur.push_back('c');
        }
        vector<int> x=z_function(cur);
        
        int ans=0;
        for(int i=pattern.size();i<x.size();i++){
            if(x[i]>=pattern.size())ans++;
        }
        
        return ans;
        
    }
};