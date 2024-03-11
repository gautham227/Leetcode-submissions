class Solution {
public:
    vector<int> cur;
    static bool cmp(char x, char y, const vector<int>& cur){
        return (cur[x-'a'] < cur[y-'a']);
    }
    string customSortString(string order, string s) {
        cur.resize(26, 30);
        for(int i = 0; i < order.size(); i++){
            cur[order[i]-'a'] = i;
        }
        sort(s.begin(), s.end(), [this](char x, char y) { return cmp(x, y, this->cur); });
        return s;
    }
};
