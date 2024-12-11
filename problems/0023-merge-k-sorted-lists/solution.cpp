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
    // ListNode* merge(ListNode* a,ListNode* b){
    //     if(a==NULL) return b;
    //     else if(b==NULL) return a;
    //     ListNode* c = new ListNode(-1);
    //     ListNode* temp = c;
    //     while(a!=NULL && b!=NULL){
    //         if(a->val <= b->val){
    //             temp->next = a;
    //             a = a->next;
    //             temp = temp->next;
    //         }
    //         else{
    //             temp->next = b;
    //             b = b->next;
    //             temp = temp->next;
    //         }
    //     }
    //     if(a!=NULL) temp->next = a;
    //     if(b!=NULL) temp->next = b;
    //     return c->next;
    // }
    // ListNode* mergeKLists(vector<ListNode*>& arr) {
    //     if(arr.empty()) return NULL;
    //     while(arr.size()>1){
    //         ListNode* a = arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* b = arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* mergeList = merge(a,b);
    //         arr.push_back(mergeList);
    //     }
    //     return arr[0];
    // }

    ListNode* merge(ListNode* a,ListNode* b){
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

    ListNode* mergeSort(vector<ListNode*>& arr,int low ,int high){
        if(low==high){
            return arr[low];
        }
        int mid = low + (high-low)/2;
        ListNode* left = mergeSort(arr,low,mid);
        ListNode* right  = mergeSort(arr,mid+1,high);
        return merge(left,right);
    }

    ListNode* mergeKLists(vector<ListNode*>& arr){
        if(arr.empty()) return NULL;
        return mergeSort(arr,0,arr.size()-1);
    }
};
