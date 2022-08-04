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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* las=NULL;
        ListNode* cur=head;
        ListNode* nex=head->next;
        while(1){
            cur->next=las;
            las=cur;
            cur=nex;
            nex=nex->next;
            if(nex==NULL){
                cur->next=las;
                las=cur;
                // cur=nex;
                break;
            }
        }
        return cur;
    }
};