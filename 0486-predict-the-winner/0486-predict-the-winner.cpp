class Solution {
public:
    
    map<vector<int> , vector<int> > dp;
    
    
    vector<int > recur(int left, int right, vector<int>& nums){
        if(left==right){
            dp[{left, right}]={nums[left], 0};
            // else dp[{left, right, pl}]={0, nums[right]};
            return dp[{left, right}];
        }
        if(dp.find({left, right})!=dp.end())return dp[{left, right}];
        
        int cur=0;
        bool flag=false;
        int lval=nums[left]+(recur(left+1,right, nums))[1];
        int rval=nums[right]+(recur(left, right-1, nums))[1];
        
        if(lval>rval)dp[{left, right}]={lval, (recur(left+1,right, nums))[0] };
        else dp[{left, right}]={rval, (recur(left,right-1, nums))[0] };
        return dp[{left, right}];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> res=recur(0, nums.size()-1, nums);
        return (res[0]>=res[1]);
        
    }
};