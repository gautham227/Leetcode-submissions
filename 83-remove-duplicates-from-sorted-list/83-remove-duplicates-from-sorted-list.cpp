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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        // int l=head->val;
        ListNode* cur=head->next, *prev=head;
        while(cur!=NULL){
            if(cur->val!=prev->val){
                prev->next=cur;
                prev=cur;
            }
            cur=cur->next;
        }
        prev->next=NULL;
        return head;
    }
};