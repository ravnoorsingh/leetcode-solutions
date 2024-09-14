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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int n = 1;
        ListNode *temp = head;
        ListNode* a = NULL, *b = NULL ,*c = NULL ,*d = NULL;
        while(temp){
            if(n==left-1) a = temp;
            if(n==left) b = temp;
            if(n==right) c = temp;
            if(n==right+1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a!=NULL)a->next = NULL;
        c->next = NULL;
        c = reverse(b);
        if(a!=NULL)a->next = c;
        b->next = d;
        if(a!=NULL)return head;
        else return c;
    }
};
