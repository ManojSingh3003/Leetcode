class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Edge cases
        if (head == nullptr || k == 1) return head;

        // 1. Count the total number of nodes
        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        // 2. Set up a dummy node to handle the head cleanly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupTail = dummy;
        curr = head;

        // 3. Reverse groups of k nodes
        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* groupTail = curr; // The first node of the group becomes the tail after reversal

            // Standard linked list reversal for exactly k nodes
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // 4. Reconnect the reversed group to the rest of the list
            prevGroupTail->next = prev; // Connect previous group's tail to the new head
            groupTail->next = curr;     // Connect the new tail to the upcoming nodes
            
            // Move prevGroupTail forward for the next group
            prevGroupTail = groupTail;

            // Decrement the count by k
            count -= k;
        }

        // Store result and clean up dummy node
        ListNode* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
    }
};