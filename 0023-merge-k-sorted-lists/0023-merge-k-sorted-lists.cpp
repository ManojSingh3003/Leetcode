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
private:
ListNode* merge(ListNode* left,ListNode* right){
    ListNode dummy(0);
    ListNode* head=&dummy;
    
    while(left!=nullptr && right!=nullptr){
        
        if(left->val <= right->val){
            head->next=left;
            left=left->next;
        }else{
            head->next=right;
            right=right->next;
        }
        head=head->next;
        
    }

    if(left!=nullptr){
        head->next=left;
    }else if(right!=nullptr){
        head->next=right;
    }

    return dummy.next;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        
        ListNode* head=nullptr;

        for(int i=0;i<lists.size();i++){
            head=merge(head,lists[i]);
        }

        return head;
    }
};