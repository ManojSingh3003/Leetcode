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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr  || head->next==nullptr )return head;
        int i=0;
        ListNode* curr=head;

        vector<int> a;
        while(curr!=nullptr){
            a.push_back(curr->val);
            curr=curr->next;
        }
        for(int i=0;i<a.size()/k;i++){
            reverse(a.begin()+i*k,a.begin()+(i+1)*k);
        }
        for(int i=0;i<a.size();i++)cout<<a[i]<<" ";

        ListNode* newhead=new ListNode(a[0]);
        curr=newhead;
        for(int i=1;i<a.size();i++){
            ListNode* node=new ListNode(a[i]);
            curr->next=node;
            curr=node;
        }

        return newhead;
    }
};