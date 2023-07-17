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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lis1=reverseList(l1);
        ListNode* lis2=reverseList(l2);
        
        int carry=0;
        
        ListNode* ans=NULL;
        ListNode* start;
        
        while(lis1!=NULL && lis2!=NULL){
            
            int curval=carry+lis1->val+lis2->val;
            lis1=lis1->next;
            lis2=lis2->next;
            ListNode* newnode = new ListNode;
            newnode->val=curval%10;
            if(ans==NULL){
                start=newnode;
            }
            else{
                ans->next=newnode;
            }
            ans=newnode;
            carry=curval/10;
        }
        
        while(lis1!=NULL){
            int curval=lis1->val+carry;
            ListNode* newnode = new ListNode;
            newnode->val=curval%10;
            lis1=lis1->next;
            
            if(ans==NULL){
                start=newnode;
            }
            else{
                ans->next=newnode;
            }
            ans=newnode;
            carry=curval/10;
            
        }
        
        while(lis2!=NULL){
            int curval=lis2->val+carry;
            ListNode* newnode = new ListNode;
            newnode->val=curval%10;
            lis2=lis2->next;
            
            if(ans==NULL){
                start=newnode;
            }
            else{
                ans->next=newnode;
            }
            ans=newnode;
            carry=curval/10;
            
        }
        
        if(carry!=0){
            ListNode* newnode = new ListNode;
            newnode->val=carry;
            
            if(ans==NULL){
                start=newnode;
            }
            else{
                ans->next=newnode;
            }
            ans=newnode;
        }
        
        
        return reverseList(start);
        
    }
};