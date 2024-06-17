class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<long long> s;
        for(long long i=0;i*i<=c;i++){
            if(2*(i*i)==c)return true;
            long long x=c-i*i;
            if(s.find(x)!=s.end())return true;
            s.insert(i*i);
        }
        return false;
    }
};