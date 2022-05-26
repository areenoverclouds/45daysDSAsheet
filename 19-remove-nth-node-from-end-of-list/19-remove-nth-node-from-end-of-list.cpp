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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        
        n = len - n + 1;
        if(n == 1) return head->next;
        
        temp = head;
        n-=2;
        while(n--){
            temp = temp->next;
        }
        if(temp->next->next != NULL)
            temp->next = temp->next->next;
        else temp->next = NULL;
        //delete(temp);
        
        return head;
        
    }
};