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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL )return head;
        if(head->next==NULL)return head;
        ListNode* pre=head;
        ListNode* cur=head->next;
        while(pre!=NULL && cur!=NULL){
            int temp=pre->val;
            pre->val=cur->val;
            cur->val=temp;
            if(cur->next==NULL || pre->next==NULL){
                break;
            }
            cur=cur->next->next;
            pre=pre->next->next;
        }
        return head;
    }
};