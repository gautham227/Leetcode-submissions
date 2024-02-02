class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int st=1;st<=9;st++){
            long long num=st;
            int val=st+1;
            while(num<=high){
                if(num>=low)ans.push_back(num);
                if(val>9)break;
                num*=10;
                num+=val;
                val++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};