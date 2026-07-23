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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* evenhead=head->next;
        ListNode* odd=nullptr;
        ListNode* even=nullptr;
        ListNode* curr=head;
        ListNode* nextnode=nullptr;
        int i=1;
        while(curr!=nullptr){
            nextnode=curr->next;
            if(i%2){
                odd=curr;
                if(curr->next!=nullptr)odd->next=curr->next->next;
                else odd->next=nullptr;
            }else{
                even=curr;
                if(curr->next!=nullptr)even->next=curr->next->next;
                else even->next=nullptr;
            }
            i++;
            curr=nextnode;
        }
        odd->next=evenhead;
        return head;
    }
};