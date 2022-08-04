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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*> > pq;
        for(auto l: lists){
            ListNode* pre=l;
            while(pre!=NULL){
                pq.push({-1*pre->val, pre});
                pre=pre->next;
            }
        }
        ListNode* x=NULL;
        ListNode* head=NULL;
        int cnt=0;
        while(!pq.empty()){
            if(cnt==0){
                head=(pq.top()).second;
                pq.pop();
                x=head;
                cnt=1;
                continue;
            }
            ListNode* n=(pq.top()).second;
            pq.pop();
            x->next=n;
            x=n;
        }
        if(x!=NULL)x->next=NULL;
        return head;
    }
};