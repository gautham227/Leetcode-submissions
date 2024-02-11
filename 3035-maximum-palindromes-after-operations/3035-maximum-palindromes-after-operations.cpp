class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> cnt(26,0);
        vector<int> lens;
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(auto ele: words[i]){
                cnt[ele-'a']++;
            }
            lens.push_back(words[i].size());
        }
        sort(lens.begin(), lens.end());
        int odd=0, even=0;
        for(auto ele: cnt){
            even+=ele/2;
            odd+=ele%2;
        }
        for(int i=0;i<lens.size();i++){
            int cur=lens[i];
            if(even<cur/2)break;
            even-=cur/2;
            if(cur%2==1){
                if(odd>0)odd--;
                else{
                    even--;
                    odd++;
                }
            }
            ans++;
        }
        return ans;
    }
};