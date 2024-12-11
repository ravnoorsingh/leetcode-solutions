/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp1 = head;
        Node* dup = new Node(-1);
        Node* temp2 = dup;
        while(temp1){
            Node* newNode = new Node(temp1->val);
            temp2->next = newNode;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        Node* a = head;
        Node* b = dup->next;
        Node* c = new Node(-1);
        Node* tempC = c;
        while(a){
            tempC->next  = a;
            tempC = tempC->next;
            a = a->next;
            tempC->next = b;
            tempC = tempC->next;
            b = b->next;
        }
        c = c->next;
        Node* t1 = c , *t2 = c;
        while(t1){
            t2 = t1->next;
            if(t1->random!=NULL)t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        Node* d1 = new Node(-1);
        temp1 = d1;
        Node* d2 = new Node(-1);
        temp2 = d2;
        Node* temp = c;
        while(temp){
            temp1->next = temp;
            temp1 = temp1->next;
            temp = temp->next;
            temp2->next = temp;
            temp2 = temp2->next;
            temp = temp->next;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;
    }
};
