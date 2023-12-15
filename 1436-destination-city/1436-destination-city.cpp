class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s1, s2;
        for(int i=0;i<paths.size();i++){
            s1.insert(paths[i][0]);
            s2.insert(paths[i][1]);
        }
        string ans="";
        for(auto &ele: s2){
            if(s1.find(ele)==s1.end()){
                ans=ele;
            }
        }
        return ans;
    }
};