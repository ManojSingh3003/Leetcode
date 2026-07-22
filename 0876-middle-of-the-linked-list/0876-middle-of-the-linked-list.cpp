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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr=head;
        int n=0;
        while(curr!=nullptr){
            curr=curr->next;
            n++;
        }

        int mid=n/2;
        int i=0;
        curr=head;
        while(curr!=nullptr && i<mid){
            curr=curr->next;
            i++;
        }
        return curr;
    }
};