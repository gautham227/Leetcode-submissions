class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> v(26, 0);
        for(int i=0;i<word.size();i++){
            v[word[i]-'a']++;
        }
        int ma=0;
        for(auto ele: v)ma=max(ma, ele);
        if(ma==1)return true;
        int f=0, s=0,z=0, o=0;
        for(int i=0;i<26;i++){
            if(v[i]==ma)f++;
            else if(v[i]==0)z++;
            else if(v[i]==1)o++;
            else if(v[i]==ma-1)s++;
            else return false;
        }
        // cout<<f<<" "<<s<<" "<<z<<" "<<o<<endl;
        if(o==1 && s==0)return true;
        return (f==1 && (o==0 || 1==ma-1));
    }
};