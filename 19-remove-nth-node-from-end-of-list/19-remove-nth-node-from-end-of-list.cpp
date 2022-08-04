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
    int len(ListNode* head){
        ListNode* present=head;
        int l=0;
        while(present!=NULL){
            present=present->next;
            l++;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=len(head);
        if(n==l){
            return head->next;
        }
        ListNode* p=NULL;
        ListNode* pre=head;
        n=l-n;
        while(n--){
            p=pre;
            pre=pre->next;
        }
        p->next=pre->next;
        return head;
    }
};