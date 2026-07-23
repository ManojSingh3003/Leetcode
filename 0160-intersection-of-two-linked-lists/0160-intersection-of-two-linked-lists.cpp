/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mp;
        ListNode* curr=headA;
        while(curr!=nullptr){
            mp[curr]++;
            curr=curr->next;
        }
        curr=headB;
        while(curr!=nullptr){
            if(mp[curr]){
                return curr;
            }
            curr=curr->next;
        }
        return nullptr;
    }
};