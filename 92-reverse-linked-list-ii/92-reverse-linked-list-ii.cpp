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
    ListNode* le;
    bool st;
    
    void rev(ListNode* cur, int l, int r){
        if(r==1)return;
        cur=cur->next;
        if(l>1){
            le=le->next;
        }
        rev(cur,l-1,r-1);
        if(le==cur || cur->next==le)st=true;
        if(st==0){
            int v=le->val;
            le->val=cur->val;
            cur->val=v;
            le=le->next;
        }
    }
    
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        le=head;
        st=false;
        rev(head,l,r);
        return head;
    }
};