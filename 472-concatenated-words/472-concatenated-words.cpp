struct node{
    node* links[26];
    bool flag= false;

    bool containskey(char c){
        return !(links[c-'a']==NULL);
    }

    node* next(char c){
        return links[c-'a'];
    }

    void setend(){
        flag=true;
    }
    
    node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
    }

};

class trie
{

node* root;

public:
    trie(){
        root= new node;
    }

    void insert(string &s){
        node* n=root;
        for(int i=0;i<s.size();i++){
            if(! n->containskey(s[i])){
                n->links[s[i]-'a']=new node;
            }
            n=n->next(s[i]);
        }
        n->setend();
    }

    bool search(string &s){
        node* n=root;
        for(int i=0;i<s.size();i++){
            // cout<<s[i]<<endl;
            if(! n->containskey(s[i])){
                return false;
            }
            n=n->next(s[i]);
        }
        return n->flag;
    }

    bool startswith(string &s){
        node* n=root;
        for(int i=0;i<s.size();i++){
            if(! n->containskey(s[i])){
                return false;
            }
            n=n->next(s[i]);
        }
        return true;
    }
    
};

class Solution {
public:
    
    trie t;
    
    bool recur(int ind, string &s, int last, vector<vector<int> > &dp, string & s1){
        // cout<<ind<<endl;
        if(ind==s.size()-1){
            s1.push_back(s[ind]);
            bool cur= t.search(s1);
            s1.pop_back();
            return cur;
        }
        if(dp[ind][last]!=-1)return dp[ind][last];
        int cur=false;
        s1.push_back(s[ind]);
        // cout<<s1<<endl;
        string s2="";
        if(t.search(s1))cur|=recur(ind+1,s,ind+1,dp,s2);
        cur|=recur(ind+1,s,last,dp,s1);
        s1.pop_back();
        return dp[ind][last]=cur;
    }
    
    static bool cmp(string & s1, string & s2){
        return s1.size()<s2.size();
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<vector<int> >dp(31, vector<int>(31,-1));
        vector<string> ans;
        string s1="";
        for(auto ele: words){
            // cout<<ele<<endl;
            for(int i=0;i<dp.size();i++){
                for(int j=0;j<dp[0].size();j++){
                    dp[i][j]=-1;
                }
            }
            if(recur(0,ele,0,dp,s1))ans.push_back(ele);
            t.insert(ele); 
        }
        
        return ans;
    }
};