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
    int length(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int len=length(head);
        int m=len/k;
        // cout<<m<<endl;
        int ex=len%k;
        ListNode* n=head;
        ListNode* l=head;
        for(int i=0;i<k;i++){
            v.push_back(n);
            int x=m;
            if(ex>0){
                x++;
                ex--;
            }
            while(x>1){
                n=n->next;
                x--;
                // if(l==1)
            }
            if(n!=NULL){
                l=n->next;
                n->next=NULL;
                n=l;
            }
        }
        return v;
    }
};