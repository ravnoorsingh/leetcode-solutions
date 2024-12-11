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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        ListNode* a = temp;
        ListNode* b = temp->next;
        ListNode* c = temp->next->next;
        int idx = 1;
        int fidx = -1;
        int sidx = -1;
        while(c){ // temp->next->next != NULL
            if( (b->val < a->val &&  b->val < c->val) || (b->val > a->val && b->val > c->val ) ){
                if(fidx==-1) fidx = idx;
                else sidx = idx;
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        int maxD = sidx - fidx;


        temp = head;
        a = temp;
        b = temp->next;
        c = temp->next->next;
        idx = 1;
        fidx = -1;
        sidx = -1;
        int minD = INT_MAX;;
        while(c){
            if( (b->val < a->val &&  b->val < c->val) || (b->val > a->val && b->val > c->val ) ){
                fidx = sidx;
                sidx = idx;
                if(fidx != -1 ) minD = min(minD,sidx-fidx);
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }

        if(sidx == -1) return {-1,-1};
        if(maxD<0) return {-1,-1};
        return {minD,maxD};
    }
};
