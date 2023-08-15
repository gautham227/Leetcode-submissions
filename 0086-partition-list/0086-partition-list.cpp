/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void swap(ListNode* a, ListNode* b){
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
        return;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* a=head;
        // ListNode* b=head;
        ListNode* c=head;
        vector<int> v,v1;
        while(c!=NULL){
            if(c->val<x){
                v1.push_back(c->val);
            }
            else{
                v.push_back(c->val);
            }
            c=c->next;
        }
        for(int i=0;i<v1.size();i++){
            a->val=v1[i];
            a=a->next;
        }
        for(int j=0;j<v.size();j++){
            a->val=v[j];
            a=a->next;
        }
        return head;
    }
};