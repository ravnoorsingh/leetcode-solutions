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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next == NULL) return head; 
        ListNode* temp = head;
        ListNode* low = new ListNode(-1);
        ListNode* high = new ListNode(-1);
        ListNode* tempLow = low;
        ListNode* tempHigh = high;
        while(temp!=NULL){
            ListNode* newNode = new ListNode(temp->val);
            if(temp->val < x){
                tempLow->next = newNode;
                tempLow = tempLow->next;
            }
            else{
                tempHigh->next = newNode;
                tempHigh = tempHigh->next;
            }
            temp = temp->next;
        }
        if(low==NULL || low->next==NULL) return high->next;
        low = low->next;
        high = high->next;
        tempLow->next = high;
        return low;
    }
};
