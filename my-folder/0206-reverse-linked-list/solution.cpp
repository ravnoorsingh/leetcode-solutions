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
    ListNode* reverseList(ListNode* head) {
        // ListNode* Curr = head;
        // ListNOde* Prev = NULL;
        // ListNOde* Next = NULL;
        // ListNode *Curr = head, *Prev = NULL , *Next = NULL;
        // while(Curr){ // Same as Curr!=NULL
        //     Next = Curr->next;
        //     Curr->next = Prev;
        //     Prev = Curr;
        //     Curr = Next;
        // }
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
        //return Prev;
    }
};
