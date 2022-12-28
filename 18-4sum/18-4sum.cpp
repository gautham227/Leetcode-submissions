class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int> >ms;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];sum+=nums[k];
                    if(target-sum>1e9 || target-sum<-1e9)continue;
                    long long present=mp[target-sum];
                    if(nums[i]==target-sum)present--;
                    if(nums[j]==target-sum)present--;
                    if(nums[k]==target-sum)present--;
                    if(present>0){
                       vector<int> v1;
                        v1={nums[i],nums[j],nums[k],(int)(target-sum)};
                        sort(v1.begin(), v1.end());
                        ms.insert(v1);
                    }
                }
            }
        }
        
        vector<vector<int> >ans;
        for(auto ele: ms)ans.push_back(ele);
        
        return ans;
    }
};