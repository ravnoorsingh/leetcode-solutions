/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;
        while(fastPointer!=NULL && fastPointer->next!=NULL){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next; 
            if(fastPointer==slowPointer) return true;
        }
        return false;
    }
};
