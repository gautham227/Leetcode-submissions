class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int ind=-1;
        for(int i=0;i<num.size();i++){
            if((num[i]-'0')%2==1){
                ind=i;
            }
        }
        for(int i=0;i<=ind;i++){
            ans.push_back(num[i]);
        }
        return ans;
    }
};