class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=1;
        char cur;
        bool flag=false;
        int ans=0;
        int n=chars.size();
        vector<char> v;
        if(chars[n-1]=='a')chars.push_back('b');
        else chars.push_back('a');
        for(int i=1;i<n+1;i++){
            if(chars[i]!=chars[i-1]){
                // cout<<cnt<<endl;
                ans++;
                v.push_back(chars[i-1]);
                if(i!=1 && chars[i-1]==chars[i-2]){
                    vector<char> v1;
                    while(cnt>0){
                        // cout<<cnt<<endl;
                        ans++;
                        int x=cnt%10;
                        cnt/=10;
                        v1.push_back((char)('0'+x));
                    }
                    // cout<<ans<<endl;
                    reverse(v1.begin(), v1.end());
                    for(auto ele: v1){v.push_back(ele);}
                }
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        chars=v;
        return ans;
    }
};