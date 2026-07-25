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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next==nullptr || k==0)return head;
        int i=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            i++;
            curr=curr->next;
        }
        int n=i;
        int x=n-k%n;
        if(x==n)return head;
        
        i=0;
        curr=head;
        ListNode* newhead=nullptr;
        while(curr!=nullptr){
            i++;
            ListNode* nextnode=curr->next;

            if(i==x+1){
                newhead=curr;
            }
            if(i==x){
                curr->next=nullptr;
            }
            if(i==n){
                curr->next=head;
            }

            curr=nextnode;
        }
        return newhead;
    }
};