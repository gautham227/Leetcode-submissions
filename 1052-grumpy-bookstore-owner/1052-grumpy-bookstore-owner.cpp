class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                ans+=customers[i];
            }
        }
        int ext=0;
        int maxi=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1)ext+=customers[i];
        }
        maxi=ext;
        for(int i=minutes;i<customers.size();i++){
            if(grumpy[i-minutes]==1)ext-=customers[i-minutes];
            if(grumpy[i]==1)ext+=customers[i];
            maxi=max(maxi, ext);
        }
        return ans+maxi;
    }
};