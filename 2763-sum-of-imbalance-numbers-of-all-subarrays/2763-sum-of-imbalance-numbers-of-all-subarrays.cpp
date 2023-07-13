class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int j=0;j<n;j++){
            set<int> s;
            int imbal=0;
            for(int i=j;i<n;i++){
                if(s.size()==0){
                    s.insert(nums[i]);
                    continue;
                }
                else if(s.find(nums[i])!=s.end()){
                    imbal+=0;
                }
                else if(nums[i]> *(--s.end())){
                    if(nums[i]!=(*(--s.end()))+1){
                        imbal++;
                    }
                }
                else if(nums[i]< *(s.begin())){
                    if(nums[i]!=(*(s.begin()))-1){
                        imbal++;
                    }
                }
                else if(s.find(nums[i]-1)!=s.end() && s.find(nums[i]+1)!=s.end()){
                    imbal--;
                }
                else if(s.find(nums[i]-1)!=s.end() || s.find(nums[i]+1)!=s.end()){
                    imbal+=0;
                }
                else{
                    imbal++;
                }
                ans+=imbal;
                s.insert(nums[i]);
            }
        }
        
        return ans;
    }
};