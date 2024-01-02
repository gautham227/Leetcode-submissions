class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=1;
        int cur=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cur++;
            }
            else{
                cur=1;
            }
            ans=max(ans,cur);
        }
        vector<vector<int> >a(ans);
        int ind=0;
        int last=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=last){
                ind=0;
            }
            a[ind].push_back(nums[i]);
            last=nums[i];
            ind++;
        }
        return a;
    }
};