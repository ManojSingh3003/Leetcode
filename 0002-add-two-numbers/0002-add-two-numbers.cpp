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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=new ListNode(0);
        ListNode* curr=head;
        while(l1!=nullptr || l2!=nullptr || carry>0){
            int n1=0;
            if(l1!=nullptr){
                n1=l1->val;
                l1=l1->next;
            }
            int n2=0;
            if(l2!=nullptr){
                n2=l2->val;
                l2=l2->next;
            }
            
            int sum=n1+n2+carry;
            carry=sum/10;
            sum=sum%10;

            curr->next=new ListNode(sum);
            curr=curr->next;

        }
        
        
        return head->next;
    }
};