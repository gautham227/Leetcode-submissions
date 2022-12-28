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
};