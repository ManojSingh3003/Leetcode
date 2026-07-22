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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* ,int> mp;
        ListNode* curr=head;
        while(curr!=nullptr){
            
            mp[curr]++;
            if(mp[curr]>1){
                return curr;
            }
            curr=curr->next;
        }
        return nullptr;
    }
};