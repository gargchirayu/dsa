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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode *prev, *temp, *cur, *next;
        prev = temp = next = NULL;
        cur = head;
        head = head->next;
        while(cur != NULL){
            temp = cur;
            cur = cur->next;
            if(!cur) break;
            next = cur->next;
            cur->next = temp;
            temp->next = next;
            if(prev != NULL) prev->next = cur;
            prev = temp;
            cur = next;
        }
        return head;
    }
};