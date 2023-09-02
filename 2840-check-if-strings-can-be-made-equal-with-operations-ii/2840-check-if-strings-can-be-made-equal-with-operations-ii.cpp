class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s3,s4,s5,s6;
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                s3.push_back(s1[i]);
                s4.push_back(s2[i]);
            }
            else{
                s5.push_back(s1[i]);
                s6.push_back(s2[i]);
            }
        }
        sort(s3.begin(), s3.end());
        sort(s4.begin(), s4.end());
        sort(s5.begin(), s5.end());
        sort(s6.begin(), s6.end());
        
        return (s3==s4 && s5==s6);
    }
};