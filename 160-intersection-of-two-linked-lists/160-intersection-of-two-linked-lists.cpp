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
    
    int len(ListNode* h){
        ListNode* cur=h;
        int l=0;
        while(cur!=NULL){
            l++;
            cur=cur->next;
        }
        return l;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=len(headA);
        int l2=len(headB);
        ListNode* h1=headA, *h2=headB;
        while(l1>l2){
            h1=h1->next;
            l1--;
        }
        while(l1<l2){
            h2=h2->next;
            l2--;
        }
        while(h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        return h1;
    }
};