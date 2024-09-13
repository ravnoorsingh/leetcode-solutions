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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n = 0;
        ListNode* temp = head;
        ListNode* tail;
        while(temp!=NULL){
            if(temp->next==NULL){
                tail=temp;
            }
            n++;
            temp = temp->next;
        }
        k=k%n;
        if(k==0) return head;
        temp = head;
        for(int i=0;i<n-k-1;i++){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }

};
