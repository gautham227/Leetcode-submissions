class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odds;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)odds.push_back(i);
        }
        int ans=0;
        int l=0, r=k-1;
        if(k>odds.size())return 0;
        while(r<odds.size()){
            int val1, val2;
            if(l==0){
                val1=odds[l]+1;
            }
            else{
                val1=odds[l]-odds[l-1];
            }
            if(r==odds.size()-1){
                val2=nums.size()-1-odds[r]+1;
            }
            else{
                val2=odds[r+1]-odds[r];
            }
            ans+=val1*val2;
            l++;r++;
        }
        return ans;
    }
};