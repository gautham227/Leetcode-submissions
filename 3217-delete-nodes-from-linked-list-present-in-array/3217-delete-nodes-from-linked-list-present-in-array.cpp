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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<bool> v(1000000+5, 0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]=1;
        }
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* h=NULL;
        while(cur!=NULL){
            if(v[cur->val]){
            }
            else{
                if(h==NULL){
                    h=cur;
                    prev=cur;
                }
                else{
                    prev->next=cur;
                    prev=cur;
                }
            }
            cur=cur->next;
        }
        prev->next=NULL;
        return h;
    }
};