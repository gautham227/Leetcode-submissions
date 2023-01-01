class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int> v;
        for(int i=0;i<rocks.size();i++){
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        int ind=0;
        int ans=0;
        while(ind<rocks.size() && a>0){
            if(a>=v[ind]){
                ans++;
                a-=v[ind];
            }
            else{
                break;
            }
            ind++;
        }
        return ans;
    }
};