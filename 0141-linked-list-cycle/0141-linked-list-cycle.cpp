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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return false;
        ListNode *f=head;
        ListNode *s=head->next;
        while(s!=NULL && s->next!=NULL){
            if(f==s)return true;
            f=f->next;
            s=s->next->next;
        }
        return false;
    }
};