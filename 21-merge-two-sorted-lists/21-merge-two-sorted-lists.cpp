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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode* pre=head;
        while(l1!= NULL || l2!=NULL){
            if(l1==NULL){
                if(head==NULL){
                    head=l2;
                    pre=head;
                }
                else{
                    pre->next=l2;
                    pre=pre->next;
                }
                l2=l2->next;
                continue;
            }
            if(l2==NULL){
                // cout<<1<<endl;
                if(head==NULL){
                    head=l1;
                    pre=head;
                }
                else{
                    pre->next=l1;
                    pre=pre->next;
                }
                l1=l1->next;
                continue;
            }
            if(l1->val>l2->val){
                if(head==NULL){
                    head=l2;
                    pre=head;
                    l2=l2->next;
                    continue;
                }
                pre->next=l2;
                l2=l2->next;
            }
            else{
                if(head==NULL){
                    head=l1;
                    pre=head;
                    l1=l1->next;
                    continue;
                }
                pre->next=l1;
                l1=l1->next;
            }
            pre=pre->next;
            
        }
        return head;
    }
};