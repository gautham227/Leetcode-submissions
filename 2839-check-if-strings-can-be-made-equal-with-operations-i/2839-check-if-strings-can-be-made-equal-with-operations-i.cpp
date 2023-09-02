class Solution {
public:
    
    string swap(string s, int a, int b){
        char temp=s[a];
        s[a]=s[b];
        s[b]=temp;
        return s;
    }
    
    bool canBeEqual(string s1, string s5) {
        set<string> v;
        v.insert(s1);
        string s2=s1, s3=s1, s4=s1;
        s2=swap(s2,0,2);
        s3=swap(s3,1,3);
        s4=swap(s4,0,2);
        s2=swap(s4,1,3);
        v.insert(s2);
        v.insert(s3);
        v.insert(s4);
        return (v.find(s5)!=v.end());
    }
};