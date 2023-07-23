class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for(char c: s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        
        int ind=0;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                s[i]=v[ind];
                ind++;
            }
        }
        return s;
    }
};