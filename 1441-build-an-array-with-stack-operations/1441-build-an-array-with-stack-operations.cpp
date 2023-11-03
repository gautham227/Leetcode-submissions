class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int ind=0;
        for(int i=1;i<=n;i++){
            ans.push_back("Push");
            if(target[ind]==i){
                ind++;
                if(ind==target.size())break;
                continue;
            }
            ans.push_back("Pop");
        }
        return ans;
    }
};