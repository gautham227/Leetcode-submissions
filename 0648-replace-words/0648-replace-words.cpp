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
    
    string findword(string &s){
        string ret="";
        
        node* n=root;
        for(int i=0;i<s.size();i++){
            if(! n->containskey(s[i])){
                return s;
            }
            n=n->next(s[i]);
            ret.push_back(s[i]);
            if(n->flag)return ret;
        }
        return s;
    }
    
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie t;
        
        for(auto &s: dictionary){
            t.insert(s);
        }
        string cur="";
        string ans="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                string newword=t.findword(cur);
                for(char x: newword)ans.push_back(x);
                ans.push_back(' ');
                cur="";
            }
            else{
                cur.push_back(sentence[i]);
            }
        }
        string newword=t.findword(cur);
        for(char x: newword)ans.push_back(x);
        return ans;
    }
};