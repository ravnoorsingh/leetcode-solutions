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

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow pointing to the left-middle in case of even length and at middle in case of odd length
        ListNode* a = head;
        ListNode* tempA = a;

        ListNode* b = reverse(slow->next);
        ListNode* tempB = b;
        slow->next = NULL;

        ListNode* c = new ListNode(-1);
        ListNode* tempC = c;

        while(tempA && tempB){
            tempC->next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;

            tempC->next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }

        tempC->next = tempA;
        head = c->next;
    }
};
