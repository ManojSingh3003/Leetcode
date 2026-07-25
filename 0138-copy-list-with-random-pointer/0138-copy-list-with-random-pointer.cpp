/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* newhead=new Node(0);
        Node* curr=head;
        while(curr!=nullptr){
            Node* node=new Node(curr->val);
            node->next=curr->next;
            curr->next=node;
            curr=curr->next->next;
        }

        curr=head;
        while(curr!=nullptr){
            if (curr->random != nullptr)curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        
        newhead->next=head->next;
        curr=head;
        while(curr != nullptr){
            Node* copyNode = curr->next; 
            Node* nextOriginal = copyNode->next; 
            
            curr->next = nextOriginal;
            
            if (nextOriginal != nullptr) {
                copyNode->next = nextOriginal->next;
            }

            curr = nextOriginal;
        }
        return newhead->next;
    }
};