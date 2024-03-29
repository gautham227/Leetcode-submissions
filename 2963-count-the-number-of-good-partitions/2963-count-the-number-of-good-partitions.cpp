#define ll long long

ll binexp(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int>pos;
        for(int i=0;i<nums.size();i++){
            pos[nums[i]]=i;
        }
        int cnt=0;
        int ind=0;
        int last=0;
        while(ind!=nums.size()){
            while(ind<=last){
                last=max(last, pos[nums[ind]]);
                ind++;
            }
            if(ind!=nums.size())last=max(last, pos[nums[ind]]);
            cnt++;
        }
        return binexp(2,cnt-1,1000000000+7);
    }
};