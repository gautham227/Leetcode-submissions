class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<int> v(26,0);
        vector<int> v1(26,0);
        for(int i=0;i<s1.size();i++){
            v[s1[i]-'a']++;
        }
        for(int i=0;i<s1.size()-1;i++){
            v1[s2[i]-'a']++;
        }
        int f=0;
        for(int i=0;i<s2.size()-s1.size()+1;i++){
            v1[s2[i+s1.size()-1]-'a']++;
            if(i!=0){
                v1[s2[i-1]-'a']--;
            }
            if(v1==v){f=1;break;}
        }
        if(f)return true;
        return false;
    }
};