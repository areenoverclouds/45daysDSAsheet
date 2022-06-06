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
        ListNode* h = headA, *t = headB;
        if(!h && !t) return NULL;
        while(h && t){
            if(h == t) return h;
            h = h->next;
            t = t->next;
            if(h == NULL && t == NULL) return NULL;
            if(h == NULL) h = headB;
            if(t == NULL) t = headA;
        }
        return h;
    }
};