class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int f=0;
        for(auto st: words){
            string st1=st;
            reverse(st1.begin(),st1.end());
            if(st==st1)return st;
        }
        return "";
    }
};