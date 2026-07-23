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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        int i=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            i++;
            curr=curr->next;
        }
        int ind=i-n+1;

        if (i == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp; // Good memory management
            return head;
        }

        curr=head;
        i=2;
        while(curr!=nullptr){
            
            if(i==ind){
                if(curr->next!=nullptr){
                    curr->next=curr->next->next;
                    // curr->next->next=nullptr;
                    break;    
                }
                
            }
            i++;
            curr=curr->next;
        }
        return head;
    }
};