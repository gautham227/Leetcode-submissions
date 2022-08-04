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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        ListNode* cur=head, *prev=NULL;
        while(cur!=NULL){
            if(cur->val==val){
                if(prev==NULL){
                    head=cur->next;
                }
                else{
                    prev->next=cur->next;
                }
                cur=cur->next;
                continue;
            }
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};