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

    ListNode* reverse(ListNode* head){
        ListNode *Curr = head, *Prev = NULL, *Next = NULL;
        while(Curr){
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        return Prev;
    }

    bool isPalindrome(ListNode* head) {
        // if the first half and the second half are reverse of each other than it is a palindrome
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow pointing to the left-middle in case of even length and at     middle in case of odd length
        ListNode* rev = reverse(slow->next);
        ListNode* a = head;
        ListNode* b = rev;
        while(b){
            if(a->val != b-> val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};
