#define ll long long
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        ll x1=x;
        ll sum=0;
        while(x1>0){
            sum+=x1%10;
            x1/=10;
        }
        if(x%sum==0)return sum;
        return -1;
    }
};