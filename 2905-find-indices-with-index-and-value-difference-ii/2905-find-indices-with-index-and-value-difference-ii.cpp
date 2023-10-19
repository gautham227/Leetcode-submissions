class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> ans;
        int n=nums.size();
        vector<int> maxind(n,0);
        maxind[n-1]=n-1;
        int ind=n-1;
        int val=nums[ind];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>val){
                ind=i;
                val=nums[i];
            }
            maxind[i]=ind;
        }
        vector<int> minind(n,0);
        ind=n-1;
        minind[ind]=n-1;
        val=nums[ind];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<val){
                ind=i;
                val=nums[i];
            }
            minind[i]=ind;
        }
        for(int i=0;i<n;i++){
            if(i+indexDifference>=n)break;
            if(abs(nums[i]-nums[maxind[i+indexDifference]])>=valueDifference){
                ans.push_back(i);
                ans.push_back(maxind[i+indexDifference]);
                break;
            }
            else if(abs(nums[i]-nums[minind[i+indexDifference]])>=valueDifference){
                ans.push_back(i);
                ans.push_back(minind[i+indexDifference]);
                break;
            }
        }
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};