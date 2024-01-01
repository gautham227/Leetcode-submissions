class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ind1=0, ind2=0;
        while(ind1<g.size() && ind2<s.size()){
            if(s[ind2]>=g[ind1]){
                ans++;
                ind2++;
                ind1++;
            }
            else{
                ind2++;
            }
        }
        return ans;
    }
};