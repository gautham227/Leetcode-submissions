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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> cur;
        ListNode* nh= new ListNode(0,head);
        ListNode* nh1=nh;
        int sum=0;
        while(nh!=NULL){
            sum+=nh->val;
            if(cur.find(sum)!=cur.end()){
                ListNode* x=cur[sum]->next;
                while(x!=nh->next){
                    sum+=x->val;
                    if(cur[sum]==x){
                        cur.erase(cur.find(sum));
                    }
                    x=x->next;
                }
                cur[sum]->next=nh->next;
            }
            else{
                cur[sum]=nh;
            }
            nh=nh->next;
        }
        
        return nh1->next;
        
    }
};