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
    ListNode* middleNode(ListNode* head) {
    //     int n = 0;
    //     ListNode* temp = head;
    //     while(temp!=NULL){
    //         n++;
    //         temp = temp->next;
    //     }
    //     n = n/2;
    //     for(int i=0;i<n;i++){
    //         head = head->next;
    //     }
    //     return head;
    // }
    ListNode* fastPointer = head;
    ListNode* slowPointer = head;
    while(fastPointer!=NULL &&fastPointer->next!=NULL ){
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    return slowPointer;
    }
};
