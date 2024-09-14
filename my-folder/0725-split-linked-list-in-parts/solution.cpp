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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        int len = n/k;
        int extra = n%k;
        temp = head;
        while(temp){
           ListNode* c = new ListNode(-1);
           ListNode* tempC = c;
           int l = len;
           if(extra>0) l++;
           extra--;
           for(int i=0;i<l;i++){
            tempC->next = temp;
            temp = temp->next;
            tempC = tempC->next;
           }
           tempC->next = NULL;
           ans.push_back(c->next);
        }
        if(ans.size() < k){
            int diff = k - ans.size();
            for(int i=0;i<diff;i++){
                ans.push_back(NULL);
            }
        } 
        return ans;
    }
};
