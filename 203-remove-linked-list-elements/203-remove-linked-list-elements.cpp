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
    ListNode* removeElements(ListNode* head, int target) {
        ListNode *prev, *cur;
        while(head && head->val == target) head = head->next;
        cur = head;
        prev = head;
        while(cur){
            if(cur->val == target){
                prev->next = prev->next->next;
                cur = cur->next;
            }
            else{
                if(cur == prev) cur = cur->next;
                else{
                    cur = cur->next;
                    prev = prev->next;
                }
            }
        }    
        return head;
    }
};