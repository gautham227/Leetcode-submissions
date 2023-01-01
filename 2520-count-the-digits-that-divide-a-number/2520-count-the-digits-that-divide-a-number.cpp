class Solution {
public:
    int countDigits(int num) {
        int num1=num;
        vector<int> s;
        while(num1>0){
            s.push_back(num1%10);
            num1/=10;
        }
        int ans=0;
        for(auto ele: s){
            if(num%ele==0)ans++;
        }
        return ans;
    }
};