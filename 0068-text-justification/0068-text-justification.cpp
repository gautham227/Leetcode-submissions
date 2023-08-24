class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> v;
        int n=words.size();
        vector<int> lens;
        for(int i=0;i<words.size();i++){
            lens.push_back(words[i].size());
        }
        int ind=0;
        while(ind<words.size()){
            int ind1=ind;
            int curpos=0;
            int blank=maxWidth;
            while(ind<n && curpos+lens[ind]<=maxWidth){
                curpos+=lens[ind];
                curpos++;
                blank-=lens[ind];
                ind++;
            }
            string x="";
            double rem=ind-ind1-1;
            if(ind!=n){
                for(int i=ind1;i<ind;i++){
                    x+=words[i];
                    if(rem==0)break;
                    for(int j=0;j<ceil((double)blank/rem);j++){
                        x+=" ";
                    }
                    blank-=ceil((double)blank/rem);
                    rem--;
                }
            }
            else{
                for(int i=ind1;i<ind;i++){
                    x+=words[i];
                    if(x.size()!=maxWidth)x+=" ";
                }
            }
            int cursize=x.size();
            for(int i=0;i<maxWidth-cursize;i++){
                x+=" ";
            }
            v.push_back(x);
        }
        return v;
    }
};