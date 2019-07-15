/////////////////
// Iteratively //
/////////////////

class Solution {
public:
    // time O(n)
    // space O(1) 
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL; 
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *fut;
        
        while (curr) {
            fut = curr->next;
            curr->next = prev; 
            prev = curr; 
            curr = fut; 
        }
        
        return prev; 
    }
};

/////////////////
// Recursively //
/////////////////

class Solution {
public:
    // time O(n)
    // space O(n) to hold recursive calls?
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        
        return reverse(NULL, head);
    }
    
    ListNode* reverse(ListNode *prev, ListNode* curr) {
        if (!curr) 
            return prev; 
        
        // tmp holds onto node so we don't lose track
        // when we reassign curr->next
        ListNode *tmp = curr->next; 
        curr->next = prev;
        return reverse(curr, tmp);
    }
};