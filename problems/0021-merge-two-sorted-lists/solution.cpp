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
    // ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    //     if(a==NULL) return b;
    //     else if(b==NULL) return a;
    //     ListNode* c = new ListNode(-1);
    //     ListNode* tempA = a;
    //     ListNode* tempB = b;
    //     ListNode* tempC = c;
    //     while(tempA!=NULL && tempB!=NULL){
    //         if(tempA->val<=tempB->val){
    //             ListNode* newNode = new ListNode(tempA->val);
    //             tempC->next = newNode;
    //             tempC = tempC->next;
    //             tempA = tempA->next;
    //             if(tempA==NULL) break;
    //         }
    //         else{
    //             ListNode* newNode = new ListNode(tempB->val);
    //             tempC->next = newNode;
    //             tempC = tempC->next;
    //             tempB = tempB->next;
    //             if(tempB==NULL) break;
    //         }
    //     }
    //     if(tempA!=NULL) tempC->next = tempA;
    //     if(tempB!=NULL) tempC->next = tempB; 
    //     return c->next;
    // }
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        if(a==NULL) return b;
        else if(b==NULL) return a;
        ListNode* c = new ListNode(-1);
        ListNode* temp = c;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else{
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if(a!=NULL) temp->next = a;
        if(b!=NULL) temp->next = b;
        return c->next;
    }
};
