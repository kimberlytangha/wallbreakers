class Solution {
public:
    // time O(n)
    // space O(1) 
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return NULL; 
        
        ListNode *odd = head;
        ListNode *evenHead = head->next;
        ListNode *even = evenHead;
        
        // need even->next bc we use even->next->next
        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next; 
            even = even->next;
        }
        
        odd->next = evenHead; 
        return head; 
    }
};