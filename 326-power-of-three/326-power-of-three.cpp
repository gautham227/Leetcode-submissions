class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        double n1=log(n)/log(3);
        if(ceil(n1)-n1<=0.00000000001 || n1-floor(n1)<=0.0000000001)return true;
        return false;
    }
};