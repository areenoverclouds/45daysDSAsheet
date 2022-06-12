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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        int flag, cont = 1;
        while(cont){
            flag = 0;
            while(head->next && head->val == head->next->val){
                head = head->next;
                flag = 1;
            }
            if(flag){
                head = head->next;
                cont = 1;
            }
            else cont = 0;
            if(!head || !head->next) break;
        }
        
        if(!head || !head->next) return head;
        
        ListNode *root = head->next, *prev = head;
        while(root->next){
            if(root->val != root->next->val){
                root = root->next;
                prev = prev->next;
                continue;
            }
            while(root->next && root->val == root->next->val){
                root = root->next;
            }
            prev->next = root->next;
            if(!root || !root->next) break;
            root = prev->next;
        }
        
        return head;
    }
};