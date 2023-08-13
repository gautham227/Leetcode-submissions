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
    
    int len(ListNode* node){
        int len=0;
        while(node!=NULL){
            len++;
            node=node->next;
        }
        return len;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(len(l2)>len(l1))swap(l1,l2);
        
        int n=len(l1);
        
        ListNode* ans= new ListNode;
        ListNode* curr=ans;
        int val=0;
        for(int i=0;i<n;i++){
            if(l1!=NULL && l2!=NULL){val+=l1->val+l2->val;l1=l1->next;l2=l2->next;}
            else {val+=l1->val;l1=l1->next;}
            curr->val=val%10;
            val/=10;
            if(i!=n-1 || val>0){curr->next = new ListNode; curr=curr->next;}
            // cur=cur->next;
            
        }
        
        if(val>0)curr->val=val;
        
        return ans;
    }
    
    ListNode* doubleIt(ListNode* head) {
        
        head = reverseList(head);
        
        ListNode * head1 = new ListNode();
        head1->val=head->val;
        ListNode* cur1=head1;
        ListNode* cur = head;
        cur=cur->next;
        while(cur!=NULL){
            // cout<<cur->val<<endl;
            ListNode* ele = new ListNode();
            ele->val=cur->val;
            cur1->next=ele;
            cur1=ele;
            cur=cur->next;
        }
        
        ListNode* ans = addTwoNumbers(head, head1);
        
        ans = reverseList(ans);
        return ans;
    }
};