class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<int> pq;
        for(auto ele: mp){
            pq.push(ele.second);
        }
        while(pq.size()>1){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            if(top1>1)pq.push(top1-1);
            if(top2>1)pq.push(top2-1);
        }
        int ans=0;
        while(pq.size()>0){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};