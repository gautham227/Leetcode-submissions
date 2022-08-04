struct node{
    node* links[26];
    int flag=0;
    
    node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
    }
    
    bool ispresent(char k){
        return (links[k-'a']!=NULL);
    }
    
    node* next(char c){
        return links[c-'a'];
    }
    
    void setflag(){
        flag=1;
    }
};


class Trie {
node* root;  
public:
    Trie() {
        root=new node;
    }
    
    void insert(string word) {
        node* n=root;
        for(int i=0;i<word.size();i++){
            if(!n->ispresent(word[i])){
                n->links[word[i]-'a']=new node;
            }
            n=n->next(word[i]);
        }
        n->setflag();
    }
    
    bool search(string word) {
        node* n=root;
        for(int i=0;i<word.size();i++){
            if(!n->ispresent(word[i])){
                return false;
            }
            n=n->next(word[i]);
        }
        return n->flag;
    }
    
    bool startsWith(string word) {
        node* n=root;
        for(int i=0;i<word.size();i++){
            if(!n->ispresent(word[i])){
                return false;
            }
            n=n->next(word[i]);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */