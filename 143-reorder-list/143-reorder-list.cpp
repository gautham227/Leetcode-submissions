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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* present=head;
        while(present!=NULL){
            v.push_back(present->val);
            present=present->next;
        }
        int x=v.size();
        int i=0;
        present=head;
        while(present!=NULL){
            if(i%2==0){
                present->val=v[i/2];
            }
            else{
                present->val=v[x-1-i/2];
            }
            present=present->next;
            i++;
        }
    }
};