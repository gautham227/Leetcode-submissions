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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=1;
        if(head==NULL)return head;
        ListNode* cur=head;
        while(cur->next!=NULL){
            len++;
            cur=cur->next;
        }
        cur->next=head;
        k=k%len;
        len=len-k-1;
        cur=head;
        for(int i=0;i<len;i++){
            cur=cur->next;
        }
        head=cur->next;
        cur->next=NULL;
        return head;
    }
};