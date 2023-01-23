class Solution {
public:
    int alternateDigitSum(int n) {
        int flag=1;
        int ans=0;
        while(n>0){
            if(flag)ans+=n%10;
            else ans-=n%10;
            n/=10;
            flag=1-flag;
        }
        if(flag==1)ans*=-1;
        return ans;
    }
};