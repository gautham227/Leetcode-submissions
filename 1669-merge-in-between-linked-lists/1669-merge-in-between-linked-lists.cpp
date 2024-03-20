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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* cur=list1;
        for(int i=0;i<a-1;i++)cur=cur->next;
        ListNode* npos=cur->next;
        for(int i=0;i<b-a+1;i++)npos=npos->next;
        cur->next=list2;
        while(cur->next!=NULL)cur=cur->next;
        cur->next=npos;
        return list1; 
    }
};