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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *ret = head, *temp = head;
        int len = 0, i;
        while(ret->next != NULL){
            ret = ret->next;
            len++;
        }
        ListNode *ans = ret;
        for(i = len; i >= 0; i--){
            temp = head;
            int copy = i;
            while(copy--){
                temp = temp->next;
            }
            ret->next = temp;
            ret = ret->next;
        }
        ret->next = NULL;
        return ans;
    }
};