class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // cout<<order<<endl;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int k=0;k<words[i].size();k++){
                for(int j=0;j<26;j++){
                    if(order[j]==words[i][k]){
                        char x=(char)('a'+j);
                        // cout<<x<<endl;
                        words[i][k]=x;
                        // cout<<words[i]<<endl;
                        break;
                    }
                }   
            }
            // cout<<words[i]<<" ";
        }
        return is_sorted(words.begin(), words.end());
    }
};