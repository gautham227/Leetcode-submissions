class Solution {
public:
    int countDistinct(vector<int>& nums, int ma, int p) {
        int n=nums.size();
        // i denotes the current length, j denotes the indexes being taken
        set<string> s;
        string v1="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                v1="";
                int cur=0;
                for(int k=i;k<=j;k++){
                    if(nums[k]%p==0)cur++;
                    v1.push_back(nums[k]);
                }
                if(cur<=ma)s.insert(v1);
            }
        }

        return s.size();
    }
};