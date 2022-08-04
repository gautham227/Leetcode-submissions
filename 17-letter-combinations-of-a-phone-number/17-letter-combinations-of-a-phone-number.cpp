class Solution {
public:
    map<int,vector<char> >m;
    vector<string> ans;
    void recur(string digits, int ind, string s1){
        if(ind==digits.size()){
            if(!s1.empty())ans.push_back(s1);
            return;
        }
        for(auto x: m[digits[ind]-'0']){
            s1.push_back(x);
            recur(digits,ind+1,s1);
            s1.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        for(int i=2;i<=6;i++){
            for(int j=1;j<=3;j++){
                m[i].push_back('a'+(i-2)*3+j-1);
                cout<<i<<" "<<m[i].back()<<" ";
            }
        }
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};
        // m[9].push_back('z');
        string s1;
        recur(digits,0,s1);
        return ans;
    }
};