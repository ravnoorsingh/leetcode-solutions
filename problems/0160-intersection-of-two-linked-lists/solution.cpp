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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        int lenA = 0;
        ListNode* tempB = headB;
        int lenB = 0;
        while(tempA!=NULL){
            lenA++;
            tempA = tempA->next;
        }
        tempA=headA;
        while(tempB!=NULL){
            lenB++;
            tempB = tempB->next;
        }
        tempB=headB;
        if(lenA>lenB){
            int diff = lenA-lenB;
            for(int i=0;i<diff;i++){
                tempA = tempA->next;
            }
            while(tempA!=tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempA;

        }
        else{
            int diff = lenB-lenA;
            for(int i=0;i<diff;i++){
                tempB = tempB->next;
            }
            while(tempA!=tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempB;
        }
        
        //return NULL;
    }
};
