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
    ListNode* ReverseList(ListNode* head){
        ListNode *Curr = head, *Prev = NULL , *Next = NULL;
        while(Curr!=NULL){
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        return Prev;
    }

    int size(ListNode* head){
        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        return n;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = ReverseList(l1);
        l2 = ReverseList(l2);
        int n1 = size(l1);
        int n2 = size(l2);
        int num = abs(n1-n2);
        ListNode* node = new ListNode(0);
        if(n1<n2){
            while(num > 0) {
                ListNode* newNode = new ListNode(0);
                newNode->next = l1;
                l1 = newNode;
                num--;
            }
        }
        else if(n2<n1){
            while(num > 0) {
                ListNode* newNode = new ListNode(0);
                newNode->next = l2;
                l2 = newNode;
                num--;
            }
        }
        l1 = ReverseList(l1);
        l2 = ReverseList(l2);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int c = 0;
        while(temp1!=NULL){
            int x = temp1->val + temp2->val + c ;
            temp1->val = x%10;
            c = x/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = l1;
        if(c!=0){
            while(temp1->next!=NULL){
                temp1 = temp1->next;
            }
            temp1->next = new ListNode(c);
        }
        return l1;
    }
};
