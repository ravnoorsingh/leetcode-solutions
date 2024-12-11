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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* temp = head;
        ListNode* tempEven = even;
        ListNode* tempOdd = odd;
        while(temp!=NULL){
            tempOdd->next = temp;
            temp = temp->next;
            tempOdd = tempOdd->next;
            if(temp==NULL) break;
            tempEven->next = temp;
            temp = temp->next;
            tempEven = tempEven->next;
        }
        tempOdd->next = even->next;
        tempEven->next = NULL;
        return odd->next;
    }
};
