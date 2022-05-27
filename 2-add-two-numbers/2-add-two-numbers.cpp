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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ret = new ListNode(0);
        ListNode* temp = ret;
        
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = 0;
            if(sum > 9) carry = sum/10;
            sum %= 10;
            ListNode* t = new ListNode(sum);
            temp->next = t;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            int sum = l1->val + carry;
            carry = 0;
            if(sum > 9) carry = sum/10;
            sum %= 10;
            ListNode* t = new ListNode(sum);
            temp->next = t;
            temp = temp->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            int sum = l2->val + carry;
            carry = 0;
            if(sum > 9) carry = sum/10;
            sum %= 10;
            ListNode* t = new ListNode(sum);
            temp->next = t;
            temp = temp->next;
            l2 = l2->next;
        }
        
        if(carry){
            ListNode* t = new ListNode(carry);
            temp->next = t;
            temp = temp->next;
        }
        return ret->next;
    }
};