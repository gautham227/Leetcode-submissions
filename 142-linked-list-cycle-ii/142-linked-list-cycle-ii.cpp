/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return head;
        ListNode* s=head,* f=head;
        bool flag=true;
        while(s!=f || flag){
            if(f->next==NULL || f->next->next==NULL || s->next==NULL)return NULL;
            s=s->next;
            f=f->next->next;
            flag=false;
        }
        while(head!=s){
            head=head->next;
            s=s->next;
        }
        return s;
    }
};