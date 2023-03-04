class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long cur=0;
        for(int i=0;i<word.size();i++){
            cur*=10;
            cur+=word[i]-'0';
            cur%=m;
            if(cur==0)ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};