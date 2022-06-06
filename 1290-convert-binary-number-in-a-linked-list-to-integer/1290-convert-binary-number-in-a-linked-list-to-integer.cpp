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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        len--;
        int ret = 0;
        while(head){
            ret += (head->val * pow(2,len));
            len--;
            head = head->next;
        }
        return ret;
    }
};