/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        vector<Node*> v;
        map<Node*, int> mp;
        Node* cur=head;
        int cnt=0;
        while(cur!=NULL){
            mp[cur]=cnt;
            cnt++;
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL){
            Node* cur1 = new Node(cur->val);
            if(v.size()>0){
                v[v.size()-1]->next=cur1;
            }
            v.push_back(cur1);
            cur=cur->next;
        }
        cur=head;
        cnt=0;
        while(cur!=NULL){
            if(cur->random!=NULL)v[cnt]->random=v[mp[cur->random]];
            cnt++;
            cur=cur->next;
        }
        return v[0];
    }
};