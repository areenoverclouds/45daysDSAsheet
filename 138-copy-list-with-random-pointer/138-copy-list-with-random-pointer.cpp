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
        
        if(head == NULL) return head;
        
        Node* ret = new Node(head->val);
        Node* temp = ret;
        Node* store = head;
        
        head = head->next;
        while(head != NULL){
            Node* t = new Node(head->val);
            temp->next = t;
            temp = temp->next;
            head = head->next;
        }
        
        head = store;
        temp = ret;
        while(head != NULL){
            if(head->random == NULL) temp->random = NULL;
            else{
                int times = 0;
                Node* reach = head->random;
                Node* p = store;
                while(p != reach){
                    times++;
                    p = p->next;
                }
                Node* q = ret;
                while(times--){
                    q = q->next;
                }
                temp->random = q;
            }
            temp = temp->next;
            head = head->next;
        }
        
        return ret;
    }
};